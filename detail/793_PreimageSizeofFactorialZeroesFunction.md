---
title: 793. Preimage Size of Factorial Zeroes Function
tags:  
    - Binary Search
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/)

## solution

用二元搜尋尋找左右邊界。

```c++
class Solution {
public:
    long trailingZeroes(long n){
        long ret = 0;
        for(long d=n;d>4;d/=5){
            ret += d/5;
        }
        return ret;
    }
    long right_bound( int k){
        long l =0, r = LONG_MAX;
        while(l<r){
            long mid = l + (r-l)/2;
            long eval = trailingZeroes(mid);
            if(eval == k) l=mid+1;
            else if(eval< k) l = mid+1;
            else if(eval >k) r = mid; 
        }
        return l-1;
    }
    long left_bound(int k){
        long l =0, r = LONG_MAX;
        while(l<r){
            long mid = l + (r-l)/2;
            long eval = trailingZeroes(mid);
            if(eval == k) r = mid;
            else if(eval < k) l = mid+1;
            else r = mid;
        }
        return l;
    }
    int preimageSizeFZF(int k) {
        
        //      0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  ... 25
        //      1   1   2   6   24  20  20  40  20  80  800 800 600 800 200 3000 8000 6000 8000 2000 40000
        //nums  0   0   0   0   0   1   1   1   1   1   2   2   2   2   2   3   3   3   3   3   4       6
        
        //  從nums 找到 nums[i] = k 最左邊的索引與最右邊的索引相減加一
        
        return right_bound(k)  -left_bound(k) + 1;
    }
};

```

## analysis
- time complexity `O(1)`  ，因為k最大也就是`LONG_MAX` `O(log(LONG_MAX) = O(32) = O(1)`
- space complexity `O(1)`