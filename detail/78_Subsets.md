---
title: 78. Subsets

tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/subsets/)
給定一個陣列，假設其元素都唯一，返回所有的子集。可以是任何順序

## solution
- 先new 一個`vector<vector<int>>`，然後用backtracking方式搜尋所有子集，直到長度超過陣列長度為止。
- 樹的每個節點的拜訪

```c++
class Solution {
public:
    void traverse(vector<int>& nums, vector<int>& path, vector<vector<int>>& ret, int s){
        // 關鍵
        ret.push_back(path);
        // 終止條件，s==nums.size()
        
        // 因為不可以重複元素需要有索引
        for(int i=s;i<nums.size();++i){
            path.push_back(nums[i]);
            traverse(nums, path, ret, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ret;
        vector<int> path;
        traverse(nums, path, ret, 0);
        return ret;
    }
};
```
## analysis

time complexity `O(2^n)`
space complexity `O(n)`