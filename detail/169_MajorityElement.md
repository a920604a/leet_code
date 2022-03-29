---
title: 169. Majority Element
tags:  
    - sorting
    - hash table
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/majority-element/)

## solution 
count sorting ，memory 會爆掉

#### option 1 - sorting
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 會超過n/2 次
        // sorting 完取中間
        sort(nums.begin(), nums.end());
        return nums[(nums.size()-1)/2];
    }
};
```
#### option 2 - hash table
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int n:nums) mp[n]++;
        int freq = 0, ret = -1;
        for(auto m:mp){
            if(m.second>freq){
                ret = m.first;
                freq = m.second;
            }
        }
        return ret;
    }
};
```

#### option 3 - vote
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1,candidate = nums[0], n = nums.size();
        for(int i=1;i<n;++i){
            if(nums[i] == candidate) count++;
            else{
                count--;
                if(count==0){
                    // 重新選出新的候選數字
                    count = 1;
                    candidate = nums[i];
                }
            }
        }
        return candidate;
    }
};
```


## analysis
- option 1 - sorting
    - time complexity `O(nlogn)`
    - sort complexity `O(1)`
- option 2 - hash table
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 3 - vote
    - time complexity `O(n)`
    - space complexity `O(1)`