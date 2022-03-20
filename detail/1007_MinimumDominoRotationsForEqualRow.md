---
title: 1007. Minimum Domino Rotations For Equal Row
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/)

## solution

#### option 1
```c++
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size() , count  = 0, cand = -1;
        for(int i=1;i<=6 ; ++i){
            count = 0;
            for(int j = 0;j<n;++j){
                if(tops[j] == i || bottoms[j] == i) count++;
            }
            if(count == n){
                cand = i;
                break;
            }
        }
        if(cand == -1) return cand;
        
        int top_n = 0, bottom_n = 0;
        for(int i=0;i<n;++i){
            if(tops[i] == cand) top_n++;
            if(bottoms[i] == cand) bottom_n++;
        }
        return min(n-top_n, n-bottom_n);
    }
};
```

#### option 2

## analysis
- time complexity `O(6n)`
- space complecity `O(1)`