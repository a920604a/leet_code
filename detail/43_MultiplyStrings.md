---
title: 43. Multiply Strings
tags:
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/multiply-strings/)

## solution
```c++
class Solution {
public:
    string multiply(string num1, string num2) {
        int n= num1.size(), m = num2.size();
        vector<int> ret(n+m,0);
        for(int i=n-1;i>-1;--i){
            for(int j= m-1;j>-1;j--){
                int p1 = i+j, p2 = i+j+1;
                int mul = ret[p2];
                mul += (num1[i]-'0')*(num2[j]-'0');
                ret[p1] += mul/10;
                ret[p2] = mul%10;
            }
        }
        int i=0;
        string ans;
        while(i<ret.size() && ret[i]==0 ) i++;
        while(i<ret.size()) ans+=to_string(ret[i++]);
        
        return ans==""?"0":ans;
    }
};
```

## analysis
- time complexity `O(nm)`
- space complexity `O(n+m)`