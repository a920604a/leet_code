---
title: 381. Insert Delete GetRandom O(1) - Duplicates allowed
tags:  
    - hash table
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/)
## solution
```c++
class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> val2idx;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        val2idx[val].insert(nums.size());
        nums.push_back(val);
        return val2idx[val].size() ==1;
    }
    
    bool remove(int val) {
        if(val2idx[val].empty()) return false;
        int idx = *val2idx[val].begin();
        val2idx[val].erase(idx);
        if(nums.size() -1 != idx){
            int t = nums.back();
            nums[idx] = t;
            val2idx[t].erase(nums.size()-1);
            val2idx[t].insert(idx);
        }
        
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```