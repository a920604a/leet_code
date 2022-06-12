---
title: 2303. Calculate Amount Paid in Taxes
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/calculate-amount-paid-in-taxes/)

## solution
```c++
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ret= 0;
        brackets.insert(brackets.begin(),{0,0});
        for(int i=1;i<brackets.size() ; ++i){
            double earn = (min(brackets[i][0], income) - brackets[i-1][0]) ;
            earn *= brackets[i][1];
            if(earn<0) break;
            ret += earn  / 100;
        }
        return ret;
    }
};
```