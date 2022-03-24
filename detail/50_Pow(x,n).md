---
title: 50. Pow(x, n)
tags:  
    - Math
categories: leetcode
comments: false
---
## [problem](https://leetcode.com/problems/powx-n/)
## solution
#### option 1 - recursive
```c++
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1) return 1;
        if(n==1) return pow(x,1);
        // avoid overflow
        if(n<0) return 1/(x*myPow(x,-(n+1)));
        else {
            // avoid time limit
            if(n%2==1) return x*myPow(x,n-1);
            else{
                double half = myPow(x,n/2);
                return half*half;
            }
        }
        
    }
};
```

#### option 2 - iterative
```c++
class Solution {
public:
    double myPow(double x, int n) {
        if(x==1 || n==0) return 1;
        double ret= 1.0;
        for(int i=n;i!=0;i/=2){
            if(i%2!=0) ret*= x;
            x*=x;
        }
        return n<0?1/ret:ret;
    }
};
```
## analysis
- time complexity `O(logn)`
- space complexity `O(1)`