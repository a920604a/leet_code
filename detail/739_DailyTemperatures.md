---
title: 739. Daily Temperatures
tags:  
    - monotonic stack
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/daily-temperatures/)

## solution
- brute force so time out
```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n =temperatures.size();
        vector<int> ret(n,0);
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                if(temperatures[j] > temperatures[i]){
                    ret[i] = j-i;
                    break;
                }
            }
        }
        return ret;
    }
};
```
- monotonic stack with index to compute number of days you have to wait after to get a warmer temperature
- 
```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> sta;
        int n = temperatures.size();
        vector<int> ret(n,0);
        for(int i=0;i<n;++i){
            while(!sta.empty() && temperatures[sta.top()] < temperatures[i] ){
                int t = sta.top();
                sta.pop();
                ret[t] = i-t;
            }
            sta.push(i);
        }
        return ret;
    }
};

```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`