/*
1472. Design Browser History

You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in the history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.


Example:

Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]
Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"


Constraints:
1 <= homepage.length <= 20
1 <= url.length <= 20
1 <= steps <= 100
homepage and url consist of  '.' or lower case English letters.
At most 5000 calls will be made to visit, back, and forward.
*/

#include <iostream>
using namespace std;

// Node class to represent each page in the browser history.
// It uses a doubly linked list structure for easy navigation.
class Node
{
public:
    string data;  // Stores the URL of the page
    Node *back;   // Pointer to the previous page in history
    Node *next;   // Pointer to the next page in history

    // Constructor to initialize a new node with a URL
    Node(string val)
    {
        this->data = val;
        this->back = nullptr;
        this->next = nullptr;
    }
};

// BrowserHistory class to manage the browser's history using a doubly linked list.
class BrowserHistory
{
    Node *currentPage;  // Pointer to the current page in history

public:
    // Constructor: Initializes the browser history with the homepage.
    // Creates a new node for the homepage and sets it as the current page.
    BrowserHistory(string homepage)
    {
        currentPage = new Node(homepage);
    }

    // visit: Visits a new URL from the current page.
    // Clears all forward history by setting the next pointer of currentPage to nullptr,
    // then creates a new node for the URL and links it as the new current page.
    void visit(string url)
    {
        Node *newNode = new Node(url);
        currentPage->next = nullptr;  // Clear forward history
        currentPage->next = newNode;  // Link new node as next
        newNode->back = currentPage;  // Set back pointer
        currentPage = newNode;        // Update current page
    }

    // back: Moves back in history by the specified number of steps.
    // Traverses backward using the back pointer, up to the available steps.
    // Returns the URL of the current page after moving.
    string back(int steps)
    {
        while (steps && currentPage->back)
        {
            currentPage = currentPage->back;
            steps--;
        }
        return currentPage->data;
    }

    // forward: Moves forward in history by the specified number of steps.
    // Traverses forward using the next pointer, up to the available steps.
    // Returns the URL of the current page after moving.
    string forward(int steps)
    {
        while (steps && currentPage->next)
        {
            currentPage = currentPage->next;
            steps--;
        }
        return currentPage->data;
    }
};

// Main function to test the BrowserHistory class with the example inputs.
int main()
{
    BrowserHistory *obj = new BrowserHistory("leetcode.com");

    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");

    cout << obj->back(1) << endl;    // facebook.com
    cout << obj->back(1) << endl;    // google.com
    cout << obj->forward(1) << endl; // facebook.com

    obj->visit("linkedin.com");

    cout << obj->forward(2) << endl; // linkedin.com (no forward history)
    cout << obj->back(2) << endl;    // google.com
    cout << obj->back(7) << endl;    // leetcode.com

    return 0;
}