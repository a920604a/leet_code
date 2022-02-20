---
title: 560. Subarray sum equals k

tags:  
    - Prefix Sum
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/subarray-sum-equals-k/)

找出連續子陣列，其總和為k 的數量

## solution
- hash table 統計連續子陣列總和及相應數量
```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //      1   1   1
        //sum   1   2   3
        // dict = {{0,1}}
        // i = 0, dict = {{0,1}, {1,1}};
        // i = 1, dict = {{0,1},{1,1},{2,1}};
        // i = 2, dict = {{0,1},{1,1},{2,1}, {3,1}};
        // hash table 代表子陣列總和與其次數
        int count = 0, n = nums.size(), sum=0;
        unordered_map<int,int> sub;
        sub[0] = 1;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            if(sub.find(sum-k)!=sub.end()) count+=sub[sum-k];
            sub[sum]++;
        }
        return count;
        
    }
};
```
## analyze
- time complexity `O(n)` 
- space complexity `O(n)`
