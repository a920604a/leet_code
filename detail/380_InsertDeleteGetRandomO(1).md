---
title: 380. Insert Delete GetRandom O(1)
tags:  
    - hash table
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/insert-delete-getrandom-o1/)

## solution

利用 array 與 hash table (key:value), key存array元素，value存array索引

```c++
class RandomizedSet {
private:
    // set : insert O(logn), delete O(logn)
    // unordered_set : insert O(1), delete O(1) 分攤後
    // map : insert O(logn), delete O(logn)
    // unordered_map : insert O(1), delete O(1) 分攤後
    
    // 存 value
    vector<int> vec;
    // key 存 list的索引，因為key 必須唯一， value 存value
    // key 存vec的value，value 唯一 , value存索引
    unordered_map<int,int> mp;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) !=mp.end()) return false;
        mp[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        
        if(mp.find(val)==mp.end()) return false;
        // 重點，需要從vector移除指定元素，但必須要O(1)
        int idx = mp[val];
        mp[vec.back()] = idx;
        swap(vec[idx], vec.back());
        // remove the last element, this 
        mp.erase(val);
        vec.pop_back();
        return true;
    }
    
    int getRandom() {
        return vec[rand()% vec.size()];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```