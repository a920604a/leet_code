---
title: 2231. Largest Number After Digit Swaps by Parity
tags:
    - sorting
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/)
## solution 
```c++
class Solution {
public:
    int largestInteger(int num) {
        vector<int> his(10,0), vec;
        while(num){
            his[num%10]++;
            vec.push_back(num%10);
            num/=10;
        }
        reverse(vec.begin(), vec.end());
        int ret = 0;
        int o = 9, e = 8;
        for(int v:vec){
            if(v&1){
                while(his[o]==0) o-=2;
                his[o]--;
                ret = 10*ret +o;
            }
            else{
                while(his[e] ==0) e-=2;
                his[e]--;
                ret = 10*ret + e;
            }
        }
        
        return ret;
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`