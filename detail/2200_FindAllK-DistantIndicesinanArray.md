---
title: 2200. Find All K-Distant Indices in an Array
tags:
    - hash table
    
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/)


## solution

```c++
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ret;
        vector<pair<int,int>> target;
        for(int i=0;i<n;++i){
            if(nums[i]==key)target.push_back(make_pair(key, i));
        }
        for(int i=0;i<n;++i){
            if(nums[i] == key){
                ret.push_back(i);
            }
            else{
                for(pair p:target){
                    if(abs(i-p.second)<=k){
                        ret.push_back(i);
                        break;
                    }
                }
            }
        }
        return ret;
        
    }
};
```

## analysis
- time complexity `O(n*mlogm)`
- space complexity `O(n)`