---
title: 264. Ugly Number II
tags:  
    - Math
    - heap
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/ugly-number-ii/)


## solution

#### option 1 - time out
```c++
class Solution {
public:
    bool isUgly(int n){
        // O(logn)
        if(n<1) return false;
        while(n%2==0) n>>=1;
        while(n%3==0) n/=3;
        while(n%5==0) n/=5;
        return n==1;
    }
    int nthUglyNumber(int n) {
        int c = 0, ret = 0, number = 1;
        while(c<n){
            if(isUgly(number)){
                c++;
                ret = number;
            }
            number++;
        }
        return ret;
    }
};
```

#### option 2 - heap
```c++
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        // 每次取最小值
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(1);
        // repr 2 3 5 倍數
        int a=1,b=1, c=1, d;
        int count =0;
        while(count++ <n){
            d = pq.top();
            pq.pop();
            // 去掉重複的值
            while(!pq.empty() && pq.top() == d) pq.pop();   
            if(d< INT_MAX/2) pq.push(d*2);
            if(d< INT_MAX/3) pq.push(d*3);
            if(d< INT_MAX/5) pq.push(d*5);
        }
        return d;
    }
};
```
#### option 3 - dp
```c++
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ret = {1};
        int p2 = 0, p3=0, p5 = 0;
        while(ret.size() < n){
            int a = ret[p2]*2, b = ret[p3]*3, c= ret[p5]*5;
            
            int mn = min(a,min(b,c));
            
            ret.push_back(mn);
            
            if(mn == a) p2++;
            if(mn == b) p3++;
            if(mn == c) p5++;
        }
        return ret.back();   
    }
};
```
## analysis
- option 1
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- option 2 
    - time complexity `O(nlogn)`
    - space complexity `O(n)`
- option 3 
    - time complexity `O(n)`
    - space complexity `O(n)`


