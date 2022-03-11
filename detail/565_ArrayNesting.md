---
title: 565. Array Nesting
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/array-nesting/)

## solution
detect cycle

```c++
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        vector<bool> visited(n, false);
        for(int i=0;i<n;++i){
            int size = 0, j = i;
            while( visited[j] == false){
                visited[j] = true;
                j = nums[j];
                size++;
                
            }
            ret = max(ret, size);
        }
        return ret;
    }
};
```

#### option 2 - constant space
```c++
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        for(int i=0;i<n;++i){
            int size = 0, j = i;
            while( nums[j] >= 0){
                int idx = nums[j];
                nums[j] = -1;
                j = idx;
                size++;
                
            }
            ret = max(ret, size);
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`