---
title: 374. Guess Number Higher or Lower
tags:  
    - Binary Search
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/guess-number-higher-or-lower/)

## solution
```c++
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while(l<=r){
            int mid = l + (r-l)/2;
            int ans = guess(mid);
            if( ans == 0) return mid;
            else if(ans == -1) r = mid-1;
            else l = mid+1;
        }
        return l;
        
    }
};
```

## analysis
- time complexity `O(logn)`
- space complexity `O(1)`
