---
title: 415. Add Strings
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/add-strings/ )

## solution
```c++
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n= num1.size(), m = num2.size();
        int len = max(n,m);
        string zero ;
        zero.append(len-min(n,m),'0');
        if(len!=n) num1 = zero + num1;
        if(len!=m) num2 = zero + num2;
        string ret;
        int carry = 0 ;
        for(int i=len-1;i>-1;--i){
            int sum = (num1[i]-'0') + (num2[i]-'0') + carry;
            ret += to_string(sum%10);
            carry = sum/10;
        }
        if(carry) ret +=to_string(carry);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`