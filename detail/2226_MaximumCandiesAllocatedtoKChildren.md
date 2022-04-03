---
title: 2226. Maximum Candies Allocated to K Children
tags:
    - Binary Search
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/)

## solution
```c++
class Solution {
public:
    long long isValid(vector<int> & candies, long long t){
        // 給定糖果，假設每人t個，可以分給多少人
       long long count = 0;
        for(int c:candies){
            count += c/t;
        }
        return count;
        
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long l = 1, r = LONG_MIN;
        for(int c:candies){
            r = max(r, (long long)c);
        }
        
        // binary search
        int ret= 0;
        while(l<=r){
            long long mid = l +(r-l)/2;
            long long eval = isValid(candies, mid);
            cout<<l<<" "<<r<<endl;
            cout<<"假設每人可以分到"<<mid<<"顆糖果\t可以分給 "<<eval<<" 人"<<endl;
            if(eval < k) r = mid-1;
            else if(eval>=k) {
                ret = mid;
                l = mid+1;
            }
            
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`