class MyHashSet
{
private:
    // unordered_set<int> st;
    vector<bool> vec; // Time: O(1) Space: O(n)
    // vector<list<int>> table;
    int bucket;

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        vec = vector<bool>(1000001, false);

        // 共 1000 桶子，用key 取餘數，判斷放在哪個桶子

        // bucket = 1000;
        // table = vector<list<int>>(bucket);
    }

    void add(int key)
    {
        // if(st.count(key)) return;
        // st.insert(key);
        vec[key] = true;

        // 用key 取餘數，判斷放在哪個桶子
        // int k = key%bucket;
        // std::list<int>::iterator findIter = std::find(table[k].begin(), table[k].end(), key);
        // if(findIter != table[k].end()) return ;
        // table[k].push_back(key);
    }

    void remove(int key)
    {
        // if(!st.count(key))  return ;
        // st.erase(key);
        vec[key] = false;

        // int k = key%bucket;
        // std::list<int>::iterator findIter = std::find(table[k].begin(), table[k].end(), key);
        // if(findIter ==table[k].end() ) return ;
        // table[k].remove(key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        // return st.count(key);
        return vec[key];

        // int k = key%bucket;
        // std::list<int>::iterator findIter = std::find(table[k].begin(), table[k].end(), key);
        // return findIter ==table[k].end()?false:true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */