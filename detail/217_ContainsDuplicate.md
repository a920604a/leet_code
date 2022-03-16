---
title: 217. Contains Duplicate

tags:  
    - hash table
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/contains-duplicate/)

找出陣列中是否一個重複的數字，如果有任何數字出現至少兩次則返回`true`，每個數字都不同則返回`false`

## Solution

#### sorting
可以先sort 是否有前後兩元素相同

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=1;i<n;++i){
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
        
    }
};
```
#### hash table
set or map

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int n:nums){
            if(s.count(n)) return true;
            s.insert(n);
        }
        return false;

        // return !(nums.size()==unordered_set<int>(nums.begin(),nums.end()).size());
    }
};
```
## analysis
- sorting
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- hash table
    - time complexity `O(n)` assuming set find operation cost const time
    - space complexity `O(n)`

