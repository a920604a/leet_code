---
title: 1678. Goal Parser Interpretation

categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/goal-parser-interpretation/)


## solution
```c++
class Solution {
public:
    string interpret(string command) {
        int l=-1, r = -1 ,  n =command.size();
        string str;
        for(int i=0;i<n;++i){
            if(command[i] == 'G') str+='G';
            else if(command[i] == '(') l =i;
            else if(command[i] ==')'){
                if(i-l==1) str+='o';
                else str+="al";
            }
        }
        return str;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`