---
title: 2259. Remove Digit From Number to Maximize Result
tags:
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/)
## solution
#### option 1 
```c++
class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<int> count;
        int n = number.size();
        for(int i=0;i<n;++i){
            if(number[i] == digit) count.push_back(i);
        }
        vector<string> ret;
        for(auto d:count){
            string str ;
            for(int i=0;i<n;++i){
                if(i!=d) str+=number[i];
            }
            ret.push_back(str);
        }
        sort(ret.begin(), ret.end());
        return ret[ret.size()-1];
        
    }
};
```
#### option 2 - greedy
```c++
class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        for(int i=0;i<n-1;++i){
            if(number[i] == digit && number[i+1]>digit){
                return number.substr(0,i) +number.substr(i+1);
            }
        }
        // find last digit
        int last_d = number.find_last_of(digit);
        return number.substr(0,last_d)+number.substr(last_d+1);
        
    }
};
```

## analysis
- option 1
    - time complexity `O(nlogn)`
    - space complexity `O(n^2)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`