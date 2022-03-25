---
title: 67. Add Binary
tags:  
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/add-binary/)

## solution
```c++
class Solution {
public:
    string addBinary(string a, string b) {
        int n =a.size(), m = b.size();
        int len = max(n,m);
        if(n<m) a = string(m-n,'0') + a;
        if(n>m) b = string(n-m, '0') +b;
        int carry = 0;
        n = len-1, m = len-1;
        string ret;
        while(n>-1 || m>-1 || carry){
            int sum = carry;
            if(n>-1) sum+=a[n--]-'0';
            if(m>-1) sum+=b[m--]-'0';
            carry = sum/2;
            ret = to_string(sum%2)+ret;
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`