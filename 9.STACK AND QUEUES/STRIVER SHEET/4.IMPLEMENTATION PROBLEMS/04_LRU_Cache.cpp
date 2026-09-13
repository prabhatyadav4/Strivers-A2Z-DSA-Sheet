/*
146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Constraints:
1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class LRUCache1
{
public:
    vector<pair<int, int>> cache;
    int n;

    LRUCache1(int capacity) { n = capacity; }

    int get(int key)
    {

        for (int i = 0; i < (int)cache.size(); i++)
        {

            if (cache[i].first == key)
            {

                int val = cache[i].second;
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(temp);

                return val;
            }
        }

        return -1;
    }

    void put(int key, int value)
    {

        for (int i = 0; i < (int)cache.size(); i++)
        {

            if (cache[i].first == key)
            {

                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }
        if (cache.size() == n)
        {
            cache.erase(cache.begin());
        }

        cache.push_back({key, value});
    }
};

class LRUCache2
{
private:
    struct Node
    {
        int key;
        int value;
        Node *prev;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node *> mp;

    Node *head;
    Node *tail;

    void addNode(Node *node)
    {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache2(int capacity)
    {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {

        if (mp.find(key) == mp.end())
        {
            return -1;
        }

        Node *node = mp[key];

        removeNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            node->value = value;
            removeNode(node);
            addNode(node);
            return;
        }

        Node *newNode = new Node(key, value);
        mp[key] = newNode;

        addNode(newNode);

        if (mp.size() > capacity)
        {
            Node *lru = tail->prev;
            mp.erase(lru->key);
            removeNode(lru);
            delete lru;
        }
    }
};

int main()
{
    cout << "LRUCache1:\n";
    LRUCache1 lruCache1(2);
    lruCache1.put(1, 1);
    lruCache1.put(2, 2);
    cout << lruCache1.get(1) << '\n'; // 1
    lruCache1.put(3, 3);
    cout << lruCache1.get(2) << '\n'; // -1
    lruCache1.put(4, 4);
    cout << lruCache1.get(1) << '\n'; // -1
    cout << lruCache1.get(3) << '\n'; // 3
    cout << lruCache1.get(4) << '\n'; // 4

    cout << "\nLRUCache2:\n";
    LRUCache2 lruCache2(2);
    lruCache2.put(1, 1);
    lruCache2.put(2, 2);
    cout << lruCache2.get(1) << '\n'; // 1
    lruCache2.put(3, 3);
    cout << lruCache2.get(2) << '\n'; // -1
    lruCache2.put(4, 4);
    cout << lruCache2.get(1) << '\n'; // -1
    cout << lruCache2.get(3) << '\n'; // 3
    cout << lruCache2.get(4) << '\n'; // 4

    return 0;
}
