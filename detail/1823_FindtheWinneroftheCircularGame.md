---
title: 1823. Find the Winner of the Circular Game
tags:
    - queue
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-the-winner-of-the-circular-game/)

## solution
#### option 1 - queue
```c++
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;++i) q.push(i);
        while(q.size()!=1){
            int t = k;
            while(--t){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};
```

#### option 2 - vector
```c++
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> vec(n,0);
        for(int i=1;i<=n;++i) vec[i-1]=i;
        int offset = 0;
        while(vec.size()!=1){
            int t = (offset+ k - 1)%vec.size() ;
            vec.erase(vec.begin() + t);
            offset = t;
        }
        return vec.front();
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`