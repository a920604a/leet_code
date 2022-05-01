---
title: 1539. Kth Missing Positive Number
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/kth-missing-positive-number/)

## solution
```c++
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //      0   1   2   3   4   5   6   7   8   9   10  11
        //              2   3   4           7               11
        //count 0   1   2   3   4   5   6   7   8   9   10  11
        //i     0   1               2   3       3   4   5   
        int count = 0;
        int i = 0, j=0;
        while(i<k){
            i++;
            count++;
            while(j<arr.size() && arr[j] == count){
                j++;count++;
            }
        }
        return count;
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexxity `O(1)`
