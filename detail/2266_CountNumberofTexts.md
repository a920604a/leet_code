---
title: 2266. Count Number of Texts
tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/count-number-of-texts/)

## solution
```c++
class Solution {
public:
    int mod = 1e+9+7;
    vector<pair<int,int>> split(string pressedKeys){
        vector<pair<int,int>> nums;
        //avoid overflow
        int cand = pressedKeys[0] - '0';
        int i=1, j=0, n = pressedKeys.size();
        for(;i<n;++i){
            if(pressedKeys[i] == pressedKeys[j]) continue;
            else{
                // string convert to integer
                nums.push_back({i-j,cand });
                // update index and cand variable
                j = i;
                cand = pressedKeys[i]-'0';
            }
        }
        nums.push_back({i-j,cand });
        return nums;
    }
    
    long dp3(int d ){
        //  2   2   2-> 3
        //  1   2   4
        
        //  2   2   2   2 -> 7
        //  1   2   4   7
        
        //  7   7   7   7 ->
        //  1   2   4   8
        if(d==0) return 0;
        if(d==1) return 1;
        if(d==2) return 2;
        if(d==3) return 4;
        
        long a = 1, b = 2, c =4, ret;
        for(int i=4;i<=d;++i){
            ret = (a+b+c)%mod;
            a=b;
            b=c;
            c=ret;
        }
        return ret;
    }
    long dp4(int d ){
        if(d==0) return 0;
        if(d==1) return 1;
        if(d==2) return 2;
        if(d==3) return 4;
        if(d==4) return 8;
        long a = 1, b = 2, c =4, dd = 8 , ret;
        for(int i=5;i<=d;++i){
            ret = (a+b+c+dd)%mod;
            a=b;
            b=c;
            c=dd;
            dd =ret;
        }
        return ret;
    }
    int countTexts(string pressedKeys) {
        // dp
        //  2   2   2   3   3
        //  1   2   4   1   2
        // 4*2
        //222=> aaa, ab, ba, c
        
        //  2   2   2   2   2
        //  1   2   4   7   13 
        //2222 => aaaa, aab, aba,baa, ac,    bb, ca
        //7777 => pppp, pqp, ppq, qpp, qq, pr,rp, s
        //22222=> aaaaa, baaa, abaa, aaba, aaab, caa, aca, aac,     bba, bab, abb, cb, bc
        vector<pair<int,int>> nums = split(pressedKeys);
        long ret = 1;
        for(const auto [numberofDigits, n]:nums){
            // // avoid overflow
            if(n %10 ==7 || n%10 == 9) ret*= dp4(numberofDigits);
            else ret *= dp3(numberofDigits);
            ret%=mod;
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`