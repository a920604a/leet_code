---
title: 386. Lexicographical Numbers
tags:  
    - backtracking
    - math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/lexicographical-numbers/)

## solution
#### option 1 - iterative
```c++
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int cur = 1;
        for(int i=0;i<n;++i){
            ret[i] = cur;
            if(cur*10 <=n) cur*=10;
            else{
                if(cur>=n) cur/=10;
                cur++;
                while(cur%10==0) cur/=10;
            }
        }
        return ret;
    }
};
```
#### option 2 - dfs
```c++
class Solution {
public:
    void dfs(int cur, int n , vector<int> & ret){
        if(cur>n) return;
        ret.push_back(cur);
        for(int i=0;i<=9;++i){
            if(cur*10 +i <= n) dfs(cur*10+i,n,ret);
            else break;
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for(int i=1;i<=9;++i) dfs(i,n,ret);
        return ret;
        
    }
};

```
## analysis
- option 1
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`
    