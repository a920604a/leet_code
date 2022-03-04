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
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        vector<int> dp(n, 0);
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        
        //2*    1   1   2   2   3   4   4   5   6
        //3*    0   1   1   1   2   2   3   3   4
        //5*    0   0   0   1   1   1   1   2   2
        //dp    2   3   4   5   6   8   9   10  12
        //   
        
        dp[0] = 1;
        for(int i=1;i<n ;++i){
            dp[i] = min(dp[t2]*2, min(dp[t3]*3, dp[t5]*5) );
            
            if(dp[i]==dp[t2]*2) t2++;
            if(dp[i]==dp[t3]*3) t3++;
            if(dp[i]==dp[t5]*5) t5++;
            // cout<<t2<<" "<<t3<<" "<<t5<<endl;
            // cout<<dp[i]<<endl;
        }
        return dp.back();
        
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


