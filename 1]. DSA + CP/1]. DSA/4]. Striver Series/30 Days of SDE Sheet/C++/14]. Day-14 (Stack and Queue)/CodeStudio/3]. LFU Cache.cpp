#include<bits/stdc++.h>
class LFUCache
{
public:
    LFUCache(int capacity)
    {
        // Write your code here.
        this -> capacity = capacity;
        size = 0;
    }

    int get(int key)
    {
        // Write your code here.
        if (values.find(key) == values.end()) {
            return -1;
        }
        update(key);
        return values[key].first;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if (!capacity) {
            return;
        }
        if (values.find(key) != values.end()) {
            values[key].first = value;
            update(key);
        } else {
            if (size == capacity) {
                int evict = keys[lfu].front();
                keys[lfu].pop_front();
                values.erase(evict);
                iters.erase(evict);
            } else {
                size++;
            }
            values[key] = {value, 1};
            keys[1].push_back(key);
            iters[key] = --keys[1].end();
            lfu = 1;
        }
    }
private:
    int capacity, size, lfu = 0;
    unordered_map<int, list<int>> keys;
    unordered_map<int, pair<int, int>> values;
    unordered_map<int, list<int>::iterator> iters;
    
    void update(int key) {
        int freq = values[key].second;
        auto iter = iters[key];
        values[key].second++;
        keys[freq].erase(iter);
        keys[freq + 1].push_back(key);
        iters[key] = --keys[freq + 1].end();
        if (keys[lfu].empty()) {
            lfu++;
        }
    }
};
