---
title: 2187. Minimum Time to Complete Trips

tags:  
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-time-to-complete-trips/)

## solution
```c++
class Solution {
public:
    long long numberOfTripsForGivenTime(vector<int>& time, long long givenTime){
        // 給定時間內可以拜訪多少trips
        // numberOfTripsForGivenTime([1,2,3], 100) => 100+50+33 = 183
        // numberOfTripsForGivenTime([1,2,3], 50) => 50+25+16=  91
        // numberOfTripsForGivenTime([1,2,3], 3) => 3/1+3/2+3/3 = 5
        long long totalTrips = 0;
        for(int t:time) {
            long long val = t;
            totalTrips+=givenTime/val;
        }
        return totalTrips;
        
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long expectTime = 0;
        long long lowestTime = 1;
        long long highestTime = 1e+14;
        while(lowestTime < highestTime){
            long long mid = lowestTime + (highestTime-lowestTime)/2;
            long long eval = numberOfTripsForGivenTime(time,mid);
            // cout<<mid<<" "<<eval<<endl;
            if(eval == totalTrips) highestTime=  mid;
            else if(eval < totalTrips) lowestTime =mid+1;
            else highestTime = mid;
        }
        return lowestTime;
    }
};
```

## analysis
- time complexity `O(nlogK)` k = 1e+14
- space complexity `O(1)`

