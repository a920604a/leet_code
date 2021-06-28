class LRUCache
{
private:
    list<pair<int, int> > l;
    unordered_map<int, list<pair<int, int> >::iterator> m;
    int cap;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        // cout<<"get"<<endl;
        auto it = m.find(key);
        if (it == m.end())
            return -1;
        // pop this node in the list add list's head
        // for(auto it: l) cout<<it.first<<" "<<it.second<<endl;
        l.splice(l.begin(), l, it->second);
        // cout<<"----splice--"<<endl;
        // for(auto it: l) cout<<it.first<<" "<<it.second<<endl;
        return it->second->second;
    }

    void put(int key, int value)
    {
        auto it = m.find(key);
        if (it != m.end())
            l.erase(it->second);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if (m.size() > cap)
        {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */