/*
355. Design Twitter

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.


Example 1:

Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.


Constraints:
1 <= userId, followerId, followeeId <= 500
0 <= tweetId <= 104
All the tweets have unique IDs.
At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.
A user cannot follow himself.
*/

/*
Intuition
To build a Twitter-like system, we need to think about what data we need to track and how to organize it efficiently.

First, let's consider what information we need to store:

Who posted what: We need to know which tweets belong to which user
When tweets were posted: To show the most recent tweets, we need to track the order of posting
Who follows whom: We need to track the follow relationships between users
The natural approach is to use hash maps (dictionaries) for quick lookups:

user_tweets: Maps each user to their list of tweet IDs
user_following: Maps each user to the set of users they follow
tweets: Maps each tweet ID to its timestamp
time: A counter that increments with each tweet to maintain chronological order
For posting tweets, we simply add the tweet to the user's list and record its timestamp. Using an incrementing counter for time is simpler than using actual timestamps and guarantees unique ordering.

The most interesting part is generating the news feed. We need to:

Identify all relevant users (the user themselves plus everyone they follow)
Collect tweets from all these users
Sort them by recency and return the top 10
The solution cleverly uses nlargest(10, tweets, key=lambda tweet: self.tweets[tweet]) to efficiently get the 10 most recent tweets without sorting the entire list. This is more efficient than sorting all tweets when we only need the top 10.

For follow/unfollow operations, we use a set to store followees for each user. Sets provide O(1) addition and removal, and automatically handle duplicates (preventing following the same user twice).

The key insight is that by separating the storage of tweets, timestamps, and follow relationships into different data structures, we can efficiently handle each operation without complex reorganization of data.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
using namespace std;

class Twitter
{
private:
    int timestamp = 0;

    // userId -> {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // followerId -> set of followees
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter()
    {
    }

    // Post a tweet
    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({++timestamp, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> pq;

        auto addTweets = [&](int id)
        {
            auto &userTweets = tweets[id];

            int count = min(10, (int)userTweets.size());

            for (int i = 0; i < count; i++)
            {
                pq.push(userTweets[userTweets.size() - 1 - i]);
            }
        };

        addTweets(userId);

        for (int followee : following[userId])
        {
            addTweets(followee);
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
        {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
        {
            following[followerId].erase(followeeId);
        }
    }
};

int main()
{
    Twitter twitter;

    auto printFeed = [&twitter](int userId, const string &description)
    {
        vector<int> feed = twitter.getNewsFeed(userId);
        cout << description << " (user " << userId << "): [";
        for (size_t i = 0; i < feed.size(); ++i)
        {
            if (i > 0)
                cout << ", ";
            cout << feed[i];
        }
        cout << "]\n";
    };

    cout << "=== Design Twitter demonstration ===\n";

    // A user sees their own tweets, even before following anyone.
    cout << "\n1. Posting and viewing a user's own tweet\n";
    twitter.postTweet(1, 5);
    printFeed(1, "Feed after user 1 posts tweet 5");

    // Following another user adds that user's tweets to the feed.
    cout << "\n2. Following another user\n";
    twitter.follow(1, 2);
    cout << "User 1 follows user 2.\n";
    twitter.postTweet(2, 6);
    printFeed(1, "Feed after user 2 posts tweet 6");

    // A feed is sorted globally by posting time, newest first.
    cout << "\n3. Feed ordering across followed users\n";
    twitter.postTweet(1, 7);
    twitter.postTweet(2, 8);
    printFeed(1, "Feed after users 1 and 2 post more tweets");

    // Unfollowing removes the followee's tweets from subsequent feeds.
    cout << "\n4. Unfollowing a user\n";
    twitter.unfollow(1, 2);
    cout << "User 1 unfollows user 2.\n";
    printFeed(1, "Feed after unfollowing user 2");

    // Following oneself has no effect; own tweets remain visible.
    cout << "\n5. Self-follow is ignored\n";
    twitter.follow(1, 1);
    twitter.postTweet(1, 9);
    printFeed(1, "Feed after user 1 attempts to follow themself and posts tweet 9");

    // A user with no posts and no followees has an empty feed.
    cout << "\n6. Empty feed for a new user\n";
    printFeed(3, "New user's feed");

    // The feed contains at most the ten newest eligible tweets.
    cout << "\n7. Feed is limited to the ten most recent tweets\n";
    for (int tweetId = 100; tweetId < 112; ++tweetId)
    {
        twitter.postTweet(3, tweetId);
    }
    printFeed(3, "User 3's feed after posting 12 tweets");

    return 0;
}
