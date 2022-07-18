class LRUCache {
public:
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int, int>>::iterator> m;
    int size;
    LRUCache(int capacity)
    {
        size=capacity;
    }
    int get(int key)
    {
        if(m.find(key)==m.end())
            return -1;
        l.splice(l.begin(),l,m[key]);
        return m[key]->second;
    }
    void put(int key, int value)
    {
        if(m.find(key)!=m.end())
        {
            l.splice(l.begin(),l,m[key]);
            m[key]->second=value;
            return;
        }
        if(l.size()==size)
        {
            auto d_key=l.back().first;
            l.pop_back();
            m.erase(d_key);
        }
        l.push_front({key,value});
        m[key]=l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */