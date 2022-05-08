---
title: 2264. Largest 3-Same-Digit Number in String
categories: leetcode
comments: false
---
## [problem](https://leetcode.com/problems/largest-3-same-digit-number-in-string/)


## solution
```c++
class Solution {
public:
    bool isGood(string str){
        return (str[0] ==str[1]) && (str[1]==str[2]);
    }
    bool isBigger(string a, string b){
        if(b.empty()) return true;
        return a[0]-'0'>b[0]-'0';
    }
    string largestGoodInteger(string num) {
        string ret;
        int n = num.size();
        for(int i=0;i<=n-3;++i){
            string temp = num.substr(i,3);
            if(isGood(temp)){
                // compare
                if(isBigger(temp,ret)) ret = temp;
            }
        }
        return ret;
    }
};
```

#### option 2
```c++
class Solution {
public:
    string largestGoodInteger(string num) {
        int ret = -1, n=num.size();
        for(int i=0;i<n-2;++i){
            if(num[i]==num[i+1] && num[i]==num[i+2] ){
                ret = max(ret, num[i]-'0');
            }
        }
        return ret!=-1? string(3,ret+'0') : "";
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)` `O(1)`