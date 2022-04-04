---
title: 705. Design HashSet
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/design-hashset/)
## solution
```c++
class MyHashSet {
private:
    vector<bool> vec;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        vec = vector<bool>(1000001,false);
    }
    
    void add(int key) {
        vec[key] = true;
        
    }
    
    void remove(int key) {
        vec[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return vec[key]==true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```
`