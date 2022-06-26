// 146. LRU Cache
/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. 

Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity 
from this operation, evict the least recently used key.

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
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put.
*/

// TLE: 20 / 22
/*
	TC: deque 

	    	find: O(n)
	    	push_back: O(1)
	    	push_front: O(1)
	    	erase: O(n)

    	unordered_map

    		find: O(1)
    		erase: O(n)
*/

class LRUCache {
public:
    
    unordered_map<int, int>mp;
    deque<int>t;
    int cap;
    
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            auto it=find(t.begin(), t.end(), key);
            t.erase(it);
            t.push_back(key);
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]=value;
            auto it=find(t.begin(), t.end(), key);
            t.erase(it);
            t.push_back(key);
        } else{
            int sz=mp.size();
            if(sz==cap){
                int key_=t.front();
                t.pop_front();
                mp.erase(key_);
                mp[key]=value;
                auto it=find(t.begin(), t.end(), key);
                if(it==t.end())
                    t.push_back(key); 
            } else{
                mp[key]=value;
                auto it=find(t.begin(), t.end(), key);
                if(it==t.end())
                    t.push_back(key);   
            }   
        }
    }
};

// -------*******-------

class Node{
    public:
    int key, value;
    Node *prev, *next;
    
    Node(): key(0), value(0), prev(nullptr), next(nullptr){}
    
    Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr){}
};


class LRUCache {
private:
    int capacity, size;
    unordered_map<int, Node*>nodes;
    Node *head=new Node();
    Node *tail=new Node();
    
    void add(Node *node){
        Node *next=head->next;
        head->next=node;
        node->next=next;
        node->prev=head;
        next->prev=node;
    }
    
    void remove(Node *node){
        Node *prev=node->prev;
        Node *next=node->next;
        prev->next=next;
        next->prev=prev;
    }
    
    void update(Node *node){
        remove(node);
        add(node);
    }
    
    void popBack(){
        Node *node=tail->prev;
        remove(node);
        nodes.erase(node->key);
        delete node;
    }

public:
    LRUCache(int capacity) {
      this->capacity=capacity;
      this->size=0;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(nodes.find(key)==nodes.end()){
            return -1;
        }
        update(nodes[key]);
        return nodes[key]->value;
    }
    
    void put(int key, int value) {
        if(nodes.find(key)!=nodes.end()){
            nodes[key]->value=value;
            update(nodes[key]);
        } else{
            Node *node=new Node(key, value);
            nodes[key]=node;
            add(node);
            if(size==capacity){
                popBack();
            } else{
                size++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */