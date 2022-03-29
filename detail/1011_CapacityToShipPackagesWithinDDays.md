---
title: 1011. Capacity To Ship Packages Within D Days
tags:  
    - Binary Search
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

輸送帶上有 i 個重量為 `weight[i]`的貨品，要`days` 天內將所有貨品運送完，每天裝載貨品最大總和不能超過最大載貨量，求運送船的最低運送能力。


## solutin

```c++
class Solution {
public:
    int cost(vector<int>& weights, int cap){
        int n = weights.size(), days = 0;
        for(int i=0;i<n;){
            int c = cap;
            while(i<n && c>=weights[i]){
                c-=weights[i++];
            }
            days++;
        }
        return days;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int l = 1, r=0;
        for(int w:weights){
            l = max(w,l);
            r+=w;
        }
        
        while(l<r){
            int cap = l + (r-l)/2;
            cout<<l<<" "<<r<<endl;
            // 運送能力 cap 下需要 evalday 才可以運送完
            int evalday = cost(weights, cap);
            // 減少運送能力，看是否還能運送完，因為題目要求最低運送能力
            if(evalday == days) r = cap;
            // 花太多天，運送太慢，加快速度 
            else if(evalday > days) l = cap +1;
            // 花太少天，運送太快，放慢速度
            else if(evalday < days) r = cap;
        }
        return l;
    }
};
```
## analysis

