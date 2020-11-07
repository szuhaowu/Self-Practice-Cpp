//Designand implement a data structure for Least Recently Used(LRU) cache.It should support the following operations : get and put.
//
//get(key) - Get the value(will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present.When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
//The cache is initialized with a positive capacity.
//
//Follow up :
//Could you do both operations in O(1) time complexity ?
//
//Example :
//
//	LRUCache cache = new LRUCache(2 /* capacity */);
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.put(4, 4);    // evicts key 1
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4


//Principle of list in c++ -> double linked list
//Doubled linked list -> every node has 1 data capacity and 1 pointer capacity which point to the next node
//The pointer of last node point to NULL
//In double linked list, only the first node could be public access
class LRUCache {
private:
    typedef list<pair<int, int>> Plist;

    int _capacity;
    Plist lst;
    //Because we need to record the key of each node, we set a heap map to record keys.
    unordered_map<int, Plist::iterator> map; //<key, Plist::iterator>


public:
    LRUCache(int capacity) :_capacity(capacity) {}

    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        touch(map[key]);
        return lst.begin()->second;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            //swap <ket,value> in Plist to the first
            touch(map[key]);
            lst.begin()->second = value;
        }
        else {
            if (map.size() == _capacity) {
                map.erase(lst.back().first);
                lst.pop_back();
            }
            lst.push_front({ key,value });
            map[key] = lst.begin();
        }
    }
 
    void touch(Plist::iterator it) {
        int key = it->first;
        int value = it->second;
        lst.erase(it);
        lst.push_front({ key,value });
        map[key] = lst.begin();
    }


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */