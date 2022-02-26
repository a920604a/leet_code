---
title: 1051. Height Checker
tags: 
    - sorting
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/height-checker/)

## solution
#### option 1 - sorting
```c++
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(),expected.end());
        int count =0, n= expected.size();
        for(int i=0;i<n;++i){
            if(expected[i]!=heights[i]) count++;
        }
        return count;
    }
};
```

#### option 2 - counting sorted 

```c++
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> count(101, 0);
        for(int h:heights) count[h]++;
        int ret = 0, i=1, n=heights.size();
        for(int j = 0;j<n;++j){
            while(count[i]==0) i++;
            if(i!= heights[j]) ret++;
            count[i]--;
            
        }
        return ret;
        
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`