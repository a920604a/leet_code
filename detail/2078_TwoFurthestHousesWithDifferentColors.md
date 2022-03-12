---
title: 2078. Two Furthest Houses With Different Colors
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/two-furthest-houses-with-different-colors/)


## solution


```c++
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int res = 0 , idx = -1;
        int n = colors.size();
        for(int i = 0 ;i<n-1 ;++i){
            for(int j = i+1;j<n;++j){
                if(colors[i]!=colors[j]) res = max(res, j-i);
            }
        }
        return res;
    }
};
```


```python
class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        ret , n= 0 , len(colors)
        for i in range(n-1):
            for j in range(i+1, n):
                if colors[i]!=colors[j]:
                    ret = max(ret, j-i)
        return ret

```

## analysis
- time complexity `O(n^2)`
- space complexity `O(1)`
