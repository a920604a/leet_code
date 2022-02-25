---
title: 1295. Find Numbers with Even Number of Digits
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)

## solution

#### option 1
```c++

class Solution {
public:
    int digits(int n){
        int  d= 0 ;
        while(n){
            d++;
            n/=10;
        }
        return d;
    }
    int findNumbers(vector<int>& nums) {
        int count;
        for(int n:nums) count+=(digits(n)%2==0?1:0);
        return count;
    }
};
```

#### option 2 - math

```c++
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int n:nums){
            int temp = floor(log10(n))+1;
            count+=(temp%2==0?1:0);
        }
        return count;
    }
};
```
## analysis
- option 1 
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- option 2 
    - time complexity `O(n)`
    - space complexity `O(1)`