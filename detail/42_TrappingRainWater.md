---
title: 42. Trapping Rain Water
tags:  
    - dp
    - monotonic stack
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/trapping-rain-water/)

## solution

#### optino 1 - dp

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0), right(n,0);
        //      0   1   0   2   1   0   1   3   2   1   2   1
        //left  0   1   1   2   2   2   2   3   3   3   3   3
        //right 3   3   3   3   3   3   3   3   2   2   2   1
        //ret               1   1   2   1           1       
        
        left[0] = height[0], right[n-1] = height[n-1];
        for(int i =1;i<n;++i) left[i] = max(left[i-1], height[i]);
        for(int i =n-2;i>-1;--i) right[i] = max(right[i+1], height[i]);
        int ret = 0;
        for(int i=1;i<n-1;++i){
            ret+= min(left[i], right[i]) - height[i];
        }
        return ret;
    }
};
```

- can reduce space complexity `O(1)`

s
#### option 2 - monotoic stack
```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ret = 0;
        stack<int> sta;
        for(int i=0;i<n;++i){
            while(!sta.empty() &&  height[sta.top()] < height[i]){
                int t = sta.top(); // 坑的底 
                sta.pop();
                if(sta.empty()) break; // 不夠形成坑
                else ret += (min(height[sta.top()], height[i]) - height[t]) * (i-sta.top()-1);
            }
            sta.push(i);
        }
        return ret;
    }
};
```
## analysis
- option 1
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(n)`