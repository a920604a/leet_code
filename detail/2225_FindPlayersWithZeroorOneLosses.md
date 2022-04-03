---
title: 2225. Find Players With Zero or One Losses
tags:
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-players-with-zero-or-one-losses/)

## sloution
```c++
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,pair<int,int>> mp;
        vector<int> winners, losers;
        for(auto m:matches){
            int win = m[0], lose = m[1];
            if(mp.count(win)){
                pair<int,int> &p= mp[win];
                p.first+=1;
            }
            else mp[win] = {1,0};
            if(mp.count(lose)){
                pair<int,int> &p= mp[lose];
                p.second+=1;
            }
            else mp[lose] = {0,1};   
        }
        for(auto m:mp){
            // winner
            if(m.second.second ==0 && m.second.first > 0){
                winners.push_back(m.first);
            }
            // loser == 1
            if(m.second.second == 1){
                losers.push_back(m.first);
            }
        }
        return {winners, losers};
        
        
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`