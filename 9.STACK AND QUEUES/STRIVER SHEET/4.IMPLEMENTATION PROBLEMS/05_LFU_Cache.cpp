/*
460. LFU Cache

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3


Constraints:
1 <= capacity <= 104
0 <= key <= 105
0 <= value <= 109
At most 2 * 105 calls will be made to get and put.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class LFUCache
{

    struct Node
    {
        int key;
        int value;
        int freq;
        Node *prev;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            freq = 1;
            prev = nullptr;
            next = nullptr;
        }
    };

    class DLL
    {
    public:
        Node *head;
        Node *tail;

        DLL()
        {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;
        }

        void addFront(Node *node)
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

        Node *removeLast()
        {
            if (head->next == tail)
            {
                return nullptr;
            }

            Node *node = tail->prev;
            removeNode(node);

            return node;
        }

        bool empty()
        {
            return head->next == tail;
        }
    };

    int capacity;
    int size;
    int minFreq;

    unordered_map<int, Node *> keyTable;
    unordered_map<int, DLL *> freqTable;

    void increaseFreq(Node *node)
    {
        int oldFreq = node->freq;

        freqTable[oldFreq]->removeNode(node);

        if (freqTable[oldFreq]->empty() && minFreq == oldFreq)
        {
            minFreq++;
        }

        node->freq++;

        if (freqTable.find(node->freq) == freqTable.end())
        {
            freqTable[node->freq] = new DLL();
        }

        freqTable[node->freq]->addFront(node);
    }

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        minFreq = 0;
    }

    int get(int key)
    {
        if (keyTable.find(key) == keyTable.end())
        {
            return -1;
        }

        Node *node = keyTable[key];

        increaseFreq(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
        {
            return;
        }

        if (keyTable.find(key) != keyTable.end())
        {
            Node *node = keyTable[key];
            node->value = value;

            increaseFreq(node);

            return;
        }

        if (size == capacity)
        {
            DLL *list = freqTable[minFreq];
            Node *node = list->removeLast();
            keyTable.erase(node->key);
            delete node;
            size--;
        }

        Node *node = new Node(key, value);

        if (freqTable.find(1) == freqTable.end())
        {
            freqTable[1] = new DLL();
        }

        freqTable[1]->addFront(node);

        keyTable[key] = node;

        minFreq = 1;

        size++;
    }
};

int main()
{
    LFUCache lfu(2);

    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << lfu.get(1) << endl; // 1

    lfu.put(3, 3);              // removes key 2
    cout << lfu.get(2) << endl; // -1
    cout << lfu.get(3) << endl; // 3

    lfu.put(4, 4);              // removes key 1
    cout << lfu.get(1) << endl; // -1
    cout << lfu.get(3) << endl; // 3
    cout << lfu.get(4) << endl; // 4

    return 0;
}
