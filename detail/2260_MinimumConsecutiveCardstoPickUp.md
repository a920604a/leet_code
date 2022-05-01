---
title: 2260. Minimum Consecutive Cards to Pick Up
tags:
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/)
## solution
#### option 1 - two pass
```c++
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,vector<int>> mp;
        int n = cards.size();
        for(int i=0;i<n;++i) mp[cards[i]].push_back(i);
        if(mp.size() == n) return -1;
        int ret = n;
        for(auto m:mp){
            if(m.second.size()>1){
                for(int i=0;i<m.second.size()-1;++i) ret = min(ret, 1 + m.second[i+1] - m.second[i]);
            }
        }
        return ret;
    }
};
```
#### option 2 - one pass
```c++
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> mp;
        int n = cards.size(), ret = INT_MAX;
        
        for(int i=0;i<n;++i){
            if(mp.count(cards[i])){
                // track last
                ret = min(ret, i-mp[cards[i]]+1);
            }
            mp[cards[i]] = i;
        }
        
        return ret==INT_MAX?-1:ret;
    }
};
```
#### option 3 - vector instead of hash 
```c++
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int last[1000001] = {}, ret = INT_MAX;
        int n = cards.size();
        for(int i=0;i<n;++i){
            if (last[cards[i]]) ret = min(ret, i - last[cards[i]] + 2);
            last[cards[i]] = i + 1;
        }
        
        return ret==INT_MAX?-1:ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`