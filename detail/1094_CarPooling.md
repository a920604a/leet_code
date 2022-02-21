---
title: 1094. Car Pooling
tags:  
    - Prefix Sum
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/car-pooling/)

## solution

```c++
class Prefix{
private:
    vector<int> diff;
public:
    Prefix(vector<int>& nums){
        int n = nums.size();
        diff = vector<int>(n, 0);
        diff[0] = nums[0];
        for(int i=1;i<n;++i){
            diff[i] = nums[i] - nums[i-1];
        }
    }
    void increment(int i, int j, int val){
        diff[i]+=val;
        if(j+1<diff.size()) diff[j+1]-=val;
    }
    vector<int> reconstruct(){
        // 還原原本陣列
        //diff  0   2   0   3   0   0   -2  0   -3  0
        //ret   0   2   2   5   5   5   3   3   0   0
        vector<int> ret(1001,0);
        ret[0] = diff[0];
        for(int i=1;i<1001;++i){
            ret[i] = ret[i-1] + diff[i];
        }
        return ret;
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //diff  0   0   0   0   0   0   0   0   0   0
        //diff  0   2   0   0   0   -2  0   0   0   0
        //diff  0   2   0   3   0   -2  0   -3  0   0   
        
        vector<int> diff(1001,0);
        Prefix prefix = Prefix(diff);
        for(vector<int>& trip:trips){
            int i = trip[1], j = trip[2]-1, val = trip[0];
            // 即乘客車上的區間是 [trip[1], trip[2] -1] 
            prefix.increment(i,j,val);
        }
        vector<int> ret = prefix.reconstruct();
        // 客車自始至终都不應該超载
        for(int r:ret){
            if(r>capacity) return false;
        }
        return true;  
    }
};
```
## analysis
- time complexity `O(n)` , n is number of trip ,`O(n*1000)`
- space complexity `O(n)`