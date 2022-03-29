---
title: 503. Next Greater Element II
tags:  
    - monotonic stack
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/next-greater-element-ii/)

## solution
```c++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n,-1);
        stack<int>sta;
        for(int i=0;i<n*2;++i){
            while(!sta.empty() && nums[sta.top()%n] <  nums[i%n]){
                int t =sta.top();
                sta.pop();
                ret[t%n] = nums[i%n];
            }
            sta.push(i% n);
        }
        for(int r:ret) cout<<r<<" ";
        return ret;
    }
};
```
## analysis

- time complexity `O(n)`
- space complexity `O(n)`