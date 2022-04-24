---
title: 2248. Intersection of Multiple Arrays
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/intersection-of-multiple-arrays/)
## solution
#### option 1 - native
```c++
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ret;
        // for(auto v:nums) sort(v.begin(), v.end());
        int n = nums.size(), m=nums[0].size();
        for(int i=0;i<m;++i){
            int count = 0;
            int cand = nums[0][i];
            for(int j=0;j<n;++j){
                for(int a:nums[j]){
                    if(cand == a) count++;
                }
            }
            if(count==n) ret.push_back(cand);
            
        }
        sort(ret.begin(), ret.end());
        return ret;
        
    }
};
```
#### option 2 


因為每個子陣列元素唯一
```c++
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> vec(10001,0);
        for(auto num:nums)
            for(int a:num) vec[a]++;
        
        vector<int> ret;
        int n = nums.size();
        for(int i=1;i<10001;++i){
            if(vec[i]==n) ret.push_back(i);
        }
        return ret;
    }
};
```
## analysis
- option 1
    - time complexity `O(nmm)`
    - space complexity `O(1)`
- option 2 
    - time complexity `O(10000n)`
    - space complexity `O(10000)`