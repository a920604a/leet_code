---
title: 2212. Maximum Points in an Archery Competition
tags:
    - backtracking
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/maximum-points-in-an-archery-competition/)

## solution
```c++
class Solution {
public:
    vector<int> candid;
    int maxScore = 0;
    void backtrack(int k, vector<int>& nums, int i, int score, vector<int> & path){
        // end condition
        if(k<0  ) return ;
        if(i==0 || k==0 ){
            if(score > maxScore){
                maxScore = score;
                candid = path;
                
            }
            return;
        }
        // win
        path.push_back(nums[i]+1);
        backtrack(k-nums[i]-1, nums, i-1, score+i, path);
        path.pop_back();
        
        // skip it
        path.push_back(0);
        backtrack(k, nums, i-1, score, path);
        path.pop_back();
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>ret(12,0);
        int sum = 0;
        vector<int> path;
        backtrack(numArrows, aliceArrows, 11, 0, path);
        for(int i=0;i<candid.size();++i){
            ret[11-i] = candid[i];
            sum+= candid[i];
        }
        ret[0]+=numArrows - sum;
        return ret;
        
    }
};
```