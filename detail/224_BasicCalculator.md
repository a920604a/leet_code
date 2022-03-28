---
title: 224. Basic Calculator
tags:
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/basic-calculator/)
## solution
```c++
class Solution {
public:
    int calculate(string s) {
        stack<int> sta;
        int res = 0;
        int sign = 1;
        int n = s.size();
        for(int i=0;i< n;++i){
            char c = s[i];
            if(c>='0' && c<='9'){
                int num = 0;
                while(i<n && s[i]>='0' && s[i]<='9'){
                    num = 10*num + (s[i++] - '0');
                }
                res += sign*num;
                i--;
            }
            else if(c=='+') sign = 1;
            else if(c=='-') sign = -1;
            else if(c=='('){
                sta.push(res);
                sta.push(sign);
                res = 0;
                sign = 1;
            }
            else if(c==')'){
                res*= sta.top();sta.pop();
                res+= sta.top(); sta.pop();
            }
        }
        return res;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`