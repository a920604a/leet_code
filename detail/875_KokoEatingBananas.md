---
title: 875. Koko Eating Bananas
tags:  
    - Binary Search
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/koko-eating-bananas/)

KoKo 要在警衛回來之前(h 小時)吃完所有香蕉`piles`，KoKo可以決定自己吃的速度k 。
計算他可以在h小時內吃掉所有香蕉的最小速度。

## solution 
Binary 變形題，不是直接比較陣列中的元素，而是將陣列中元素餵進函數得到輸出，在比較大小，去決定左右索引如何移動。

```c++
class Solution {
public:
    int cost(vector<int>& piles, int speed){
        int hours = 0;
        for(int p:piles){
            hours += p/speed;
            if(p%speed) hours++;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l =1,r =1;
        // 每小時最多吃多少根，取決於最大堆數量
        for(int p:piles) r = max(p, r);
        
        while(l<r){
            int speed = l + (r-l)/2;
            // 如果用每小時 speed 速度吃的話，需要hours 小時才吃得完
            int hours = cost(piles, speed);
            if(hours == h) r = speed;
            // 警衛回來前吃不完，需要加快速度
            if(hours > h) l= speed+1;
            // 吃太快，放慢速度
            else r =  speed;
        }
        return l;
    }
};
```
```c++
class Solution {
public:
    int cost(vector<int> &piles, int speed){
        int hours = 0;
        for(int p:piles){
            hours+=p/speed;
            if(p%speed) hours++;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l =1 , r  = 1;
        for(int p:piles) r = max(r, p);
        while(l<=r){
            int mid = l+ (r-l)/2;
            int hours = cost(piles, mid);
            // eat fast
            if(hours <= h ) r = mid-1;
            // eat slow
            else if(hours > h) l = mid+1;
        }
        return l;
    }
};
```
## analysis
- time complexity `O(nlogm)` , n is number of piles and m os range of k
- space complexity `O(1)`