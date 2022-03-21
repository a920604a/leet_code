---
title: 769. Max Chunks To Make Sorted
tags:
    - stack
    - greedy
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/max-chunks-to-make-sorted/)

## solution
#### option 1 - stack
```c++
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<pair<int,int>> sta;
        int n =arr.size();
        for(int i=0;i<n;++i){
            int mn = arr[i], mx = arr[i];
            while(!sta.empty()){
                auto top = sta.top();
                if(arr[i] < top.second){
                    mn = min(top.first, mn);
                    mx = max(top.second, mx);
                    sta.pop();
                }
                else break;
            }
            sta.push({mn, mx});
        }
        return sta.size();
    }
};
```
#### option 2 
```c++
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ret = 0, n = arr.size();
        for(int i=0;i<n;++i){
            int cur = arr[i], j= i+1;
            for(;j<=cur;++j){
                cur = max(cur, arr[j]);
                if(cur >= arr.back()) return ret+1;
            }
            i = j-1;
            ++ret;
            
        }
        return ret;
    }
};
```
#### option 3 - greedy
```c++
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int mx = 0, ret =0, n= arr.size();
        for(int i=0;i<n;++i){
            mx = max(arr[i], mx);
            if(mx == i) ret++;
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)` `O(1)`

