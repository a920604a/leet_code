---
title: 1870. Minimum Speed to Arrive on Time
tags:  
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/)
## solution
```c++
class Solution {
public:
    double cost(vector<int> & dist, int speed){
        double hours = 0;
        for(int i=0;i<dist.size() ; ++i){
            if(i == dist.size()-1) hours+= dist[i]*1.0/speed;
            else hours+=ceil((double)dist[i]/speed);
        }
        return hours;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e+7;
        if(hour <= dist.size()-1) return -1;
        while(l<r){
            int mid = l + (r-l)/2;
            double hours = cost(dist, mid);
            if(hours > hour) l = mid  +1 ;
            else r = mid ;
        }
        return l;
        
    }
};
```

## analysis
- time complexity `O(logn)`
- space complexity `O(1)`