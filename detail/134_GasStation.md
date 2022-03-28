---
title: 134. Gas Station
tags:
    - Greedy
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/gas-station/)

## solution
- brute force , TLE
```c++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0;i<n ; ++i){
            // i 為起點
            int cur = 0;
            for(int j = 0;j<n ; j++){
                cur+=(gas[(i+j)%n] - cost[(i+j)%n] );
                if(cur<0) break;
            }
            if(cur>=0) return i;
        }
        return -1;
    }
};
```

#### option 1 - greedy
```c++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 如果選擇起點 i 作為起點，恰好無法 走到站點 j ，那麼i 和 j 中間的任一站點 k 都不可能作為起點。
        // 比如説從 站點1 出發，走到站點5時油箱油量為負數，那說明站點1 洽好無法 走到站點5，
        // 也就是說你無法從站點2 3 4 任一站點出發到達站點 5 因為站點5 到達時 油箱油量並然被減到負數。
        
        int n = gas.size();
        int sum = 0;
        for(int i=0;i<n;++i) sum+= (gas[i] - cost[i]);
        if(sum<0) return -1;
        int tank = 0; // 油箱油量
        int start = 0; // 起點
        for(int i=0;i<n;++i){
            tank += (gas[i] - cost[i]);
            if(tank<0){
                start = i+1;
                tank = 0;
            }
        }
        return start==n ? 0 :start;
        
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complecity `O(1)`