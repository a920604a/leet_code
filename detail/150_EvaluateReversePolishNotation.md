---
title: 150. Evaluate Reverse Polish Notation
tags:
    - stack
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
## solution

```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        int ret= 0;
        for(string str:tokens ){
            if(str == "+" || str == "-" || str=="*" || str=="/"){
                int a = sta.top(); sta.pop();
                int b = sta.top(); sta.pop();
                if(str == "+") sta.push(b+a);
                else if(str =="-") sta.push(b-a);
                else if(str=="*") sta.push(b*a);
                else if(str=="/") sta.push(b/a);
                
            }
            else{
                sta.push(stoi(str));
            }
        }
        return sta.top();
    }
};
```

## analysis
- time complexity `O(n)`
- space complexit `O(n)`