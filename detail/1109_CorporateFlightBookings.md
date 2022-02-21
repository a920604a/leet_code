---
title: 1109. Corporate Flight Bookings
tags:  
    - Prefix Sum
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/corporate-flight-bookings/)

## solution
```c++
class Diff{
private:
    vector<int> diff;
public:
    Diff(vector<int>& nums){
        diff = vector<int>(nums.size(),0);
        diff[0] = nums[0];
        for(int i=1;i<nums.size();i++) diff[i] = nums[i] - nums[i-1];
    }
    void increment(int i,int j, int val){
        //  0   0   0   0   0   0   0
        //  10  0   -10
        //  10  20  -10 -20
        //  10  45  -10 -20 -25 0   0
        diff[i]+=val;
        if(j+1<diff.size()) diff[j+1]-=val;
    }
    vector<int> reconstructure(){
        vector<int> ret(diff.size(),0);
        //  10  45  -10 -20 -25 0   0
        //  10  55  45  25  
        ret[0] = diff[0];
        for(int i=1;i<diff.size();++i) ret[i] = diff[i] + ret[i-1];
        return ret;
    }
};
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> num(n,0);
        Diff diff = Diff(num);
        for(vector<int> & book:bookings){
            int i = book[0]-1, j = book[1]-1, val = book[2];
            diff.increment(i,j, val);
        }
        vector<int> ret = diff.reconstructure();
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`