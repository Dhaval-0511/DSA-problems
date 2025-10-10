#include <unordered_map>
#include <list>

class LFUCache {
public:
    int capacity, minFreq;
    // Key to (value, frequency)
    std::unordered_map<int, std::pair<int, int>> keyToValFreq;
    // Frequency to list of keys (recent order: front=most, back=least)
    std::unordered_map<int, std::list<int>> freqToKeys;
    // Key to iterator in its frequency list
    std::unordered_map<int, std::list<int>::iterator> keyToIter;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end())
            return -1;
        // Get current val and freq
        int val = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;
        // Remove key from current frequency list
        freqToKeys[freq].erase(keyToIter[key]);
        // Update minFreq if needed
        if (freqToKeys[freq].empty() && freq == minFreq)
            minFreq++;
        // Increase frequency
        freq++;
        keyToValFreq[key].second = freq;
        freqToKeys[freq].push_front(key);
        keyToIter[key] = freqToKeys[freq].begin();
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;
        // If key exists, just update value and its frequency
        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;
            get(key); // Will update frequency as in get operation
            return;
        }
        // If at capacity, evict LRU of minFreq
        if (keyToValFreq.size() == capacity) {
            int evictKey = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            keyToValFreq.erase(evictKey);
            keyToIter.erase(evictKey);
        }
        // Insert new key with freq=1
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
};


// prblm:https://leetcode.com/problems/lfu-cache