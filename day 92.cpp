#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int,int>> cacheList; // key-value pairs in order of usage, front is MRU
    unordered_map<int, list<pair<int,int>>::iterator> cacheMap; // key -> iterator in list
    
    // Move the accessed node to the front
    void moveToFront(int key) {
        auto it = cacheMap[key];
        cacheList.splice(cacheList.begin(), cacheList, it);
        cacheMap[key] = cacheList.begin();
    }

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end())
            return -1;
        moveToFront(key);
        return cacheMap[key]->second;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Key exists: update value and move to front
            cacheMap[key]->second = value;
            moveToFront(key);
        } else {
            // Insert new key-value
            if ((int)cacheList.size() == capacity) {
                // Evict least recently used
                int lruKey = cacheList.back().first;
                cacheList.pop_back();
                cacheMap.erase(lruKey);
            }
            cacheList.push_front({key, value});
            cacheMap[key] = cacheList.begin();
        }
    }
};


// prblm:https://leetcode.com/problems/lru-cache