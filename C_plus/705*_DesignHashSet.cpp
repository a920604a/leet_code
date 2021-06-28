// option 1 use vector
// class MyHashSet {
// private:
//     vector<int> data ;
// public:
//     /** Initialize your data structure here. */
//     MyHashSet() {
//         data.resize(1000001,0);
//     }

//     void add(int key) {
//         data[key]++;
//     }

//     void remove(int key) {
//         data[key]=0;

//     }

//     /** Returns true if this set contains the specified element */
//     bool contains(int key) {
//         return data[key]>0?true:false;
//     }
// };

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// option 2 use STL list and bucket
class MyHashSet
{
private:
    int bucket;
    vector<list<int> > table;

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        bucket = 1000;
        table = vector<list<int> >(bucket);
    }

    void add(int key)
    {
        int hashkey = key % bucket;
        if (contains(key))
            return;
        table[hashkey].push_back(key);
    }

    void remove(int key)
    {
        int hashkey = key % bucket;
        for (auto lt = table[hashkey].begin(); lt != table[hashkey].end(); ++lt)
        {
            if (*lt == key)
            {
                table[hashkey].erase(lt);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {

        int hashkey = key % bucket;
        for (auto lt = table[hashkey].begin(); lt != table[hashkey].end(); ++lt)
        {
            if (*lt == key)
                return true;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */