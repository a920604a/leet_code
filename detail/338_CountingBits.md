---
title: 338. Counting Bits

tags:  
    - Bit Manipulation
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/counting-bits/)

## solution

如果i不是2的指數，那 `i&(i-1)` 可以找到比i小的2的指數

#### option 1

```c++
class Solution {
public:
    int count(int n){
        int ret = 0;
        while(n){
            ret++;
            n &= (n-1);
        }
        return ret;
    }
    vector<int> countBits(int n) {
        vector<int> ret(n+1,0);
        //  0   1   2   3   4   5
        //  0   1   1   2   
        for(int i=1;i<n+1;++i){
            ret[i] = count(i);
        }
        return ret;
    }
};
```
#### option 2
```c++
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1,0);
        //  0   1   2   3   4   5
        //  0   1   
        for(int i=1;i<n+1;++i){
            // ret[i] = ret[ i&(i-1)] +1;
            if(i%2==0) ret[i] = ret[i/2];
            else ret[i] = ret[i-1]+1;
        }
        return ret;
    }
};
```
#### option 3
```c++
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1,0);
        //  0   1   2   3   4   5   6   7   8   
        //  0   1   1   2   1   2   2   3   1
        for(int i=1;i<=n;++i){
            if( (i&(i-1))==0) ret[i] = 1;
            else ret[i] = ret[i&(i-1)]+1;
        }
        return ret;
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

