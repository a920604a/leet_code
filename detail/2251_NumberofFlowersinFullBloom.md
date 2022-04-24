---
title: 2251. Number of Flowers in Full Bloom
tags:
    - Binary Search
    - Prefix Sum
    - Sweep line
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/number-of-flowers-in-full-bloom)

## solution
沒解出來, out of memory
```c++
class Solution {
public:
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        // prefix sum => out of memory
        int l =0, r = 0;
        for(auto f:flowers) r = max(r, f[1]);
        for(auto p:persons) r= max(r, p);
        vector<int> prefix(r+1,0);
        for(auto f:flowers){
            prefix[f[0]]++;
            if( f[1]+1 < r+1) prefix[f[1]+1]--;
        }
        for(int i=1;i<r+1;++i) prefix[i]+=prefix[i-1];
        vector<int> ret;
        for(int p:persons) ret.push_back(prefix[p]);
        return ret;
      
    }
};
```
#### option 1 - reduce prefix to use hash 

```c++
class Solution {
public:
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        // prefix sum => out of memory
        map<int,int> mp;
        // order by key
        for(const auto & f:flowers){
            mp[f[0]]++;
            mp[f[1]+1]--;
        }
        //  {1,1} {3,1} {4,1} {7,-1} {8,-1} {9,1} {13,-1} {14,-1}
        auto it = next(mp.begin());
        // recovery prefix amp
        for(;it!=mp.end();++it) it->second+=prev(it)->second;
        //  {1,1} {3,2} {4,3} {7,2} {8,1} {9,2} {13,1} {14,0}
        vector<int> ret;
        for(const auto& p:persons){
            it = mp.upper_bound(p);
            // upper_bound 找出 key 大於 p 的最小位置，
            // p 落在 it 與it-1 區間
            if(it==mp.begin()) ret.push_back(0);
            else ret.push_back(prev(it)->second);
        }
        return ret;
        
        
        
    }
};
```

## analysis
- time complexity `O(nlogm)`
- space complexity `O(m)`