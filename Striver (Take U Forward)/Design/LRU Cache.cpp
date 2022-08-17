// Striver Explanation: https://youtu.be/xDEuM5qa0zg?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma
// Striver Code: https://youtu.be/Xc4sICC8m4M?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma
// Leetcode Link: https://leetcode.com/problems/lru-cache/
// InterviewBit Link: https://www.interviewbit.com/problems/lru-cache/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int key, int val) : key(key), val(val), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> lookUp;
    
    void addNode(Node* newNode) {
        // Storing the current head->next 
        Node* headNext = head->next;
        
        // Assigning next and prev for newNode
        newNode->next = headNext;
        newNode->prev = head;
        
        // Updating the next of head and prev of headNext
        head->next = newNode;
        headNext->prev = newNode;
    }
    
    void deleteNode(Node* delNode) {
        // Storing the next and prev 
        // of the node to be deleted
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        
        // Updating by assigning to each other
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
public:
    LRUCache(int capacity) : capacity(capacity), head(new Node(-1, -1)), tail(new Node(-1, -1)) {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // Check if node exists in LRU cache
        if(lookUp.find(key) != lookUp.end()) {
            
            // If exists, retrieve the node
            // and store the ans
            Node* ansNode = lookUp[key];
            int ans = ansNode->val;
            
            // Reconfigure retrieved node as the 
            // recently used node (because you used it)
            
            // Step 1: Remove node from cache
            lookUp.erase(key);
            deleteNode(ansNode);
            
            // Step 2: Add the node back into cache
            addNode(ansNode);
            lookUp[key] = ansNode;
            
            // Finally return ans
            return ans;
        }
        
        // Else if node does not exist
        return -1;
    }
    
    void put(int key, int value) {
        // If the node to be put already exists,
        // delete it from cache
        if(lookUp.find(key) != lookUp.end()) {
            deleteNode(lookUp[key]);
            lookUp.erase(key);
        }
        
        // If size of LRU cache is maxed out,
        // delete least recently used node
        if(lookUp.size() == this->capacity) {
            lookUp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        // Add the requested node
        addNode(new Node(key, value));
        lookUp[key] = head->next;
    }
    
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */