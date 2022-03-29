---
title: 454. 4Sum II
tags:  
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/4sum-ii/)

## solution

利用hash table 紀錄前兩陣列總和與及次數。再去拜訪後兩陣列尋找相反數是否存在hash table。

```c++
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>mp;
        int a= nums1.size(), b = nums2.size(), c= nums3.size(),d = nums4.size();
        for(int i=0;i<a;++i){
            for(int j=0;j<b;++j){
                mp[nums1[i] + nums2[j]]++;
            }
        }
        int ret = 0;
        for(int i=0;i<c;++i){
            for(int j=0;j<d;++j){
                int target = - (nums3[i] + nums4[j]);
                ret+=mp[target];
            }
        }
        return ret;
    }
};

```


## analysis
- time complexity `O(n^2)`
- space complexity `O(n)`