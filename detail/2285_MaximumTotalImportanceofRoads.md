---
title: 2285. Maximum Total Importance of Roads
tags: 
    - hash table 
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/maximum-total-importance-of-roads/)
## solution
```c++
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // 最多連結的給最大，然後遞減
        vector<int> vec(n,0);
        vector<pair<int, int> > arr;
        unordered_map<int,int> memo;
        long long ret= 0;
        
        for(auto road:roads){
            vec[road[0]]++;
            vec[road[1]]++;
        }
        for(int i=0;i<n;++i){
            arr.push_back(make_pair(i,vec[i]));
        }
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.second>b.second;
        });
        int cur =n;
        for(auto &[a,b]:arr){
            b = cur--;
            memo[a] = b;
        }
        for(auto road:roads){
            ret+= memo[road[0]]+memo[road[1]];
        }
        
        return ret;
        
    }
};
```
## analysis
- time complexity `O(nlogn)`