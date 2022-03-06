---
title: 2194. Cells in a Range on an Excel Sheet
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/)


## solution

```c++
class Solution {
public:
    vector<string> cellsInRange(string s) {
        char a = s[0]+1, b = s[3];
        vector<string> ret;
        for(char c = s[0] ;c<=s[3] ; ++c){
            for(int i=int(s[1]);i<=int(s[4]) ; ++i){
                string temp ;
                temp+=c;
                temp+= char(i);
                ret.push_back(temp);
            
            }    
        }
        return ret;
    }
};

```
## analysis
- time complexity `O(nm)`
- space complexity `O(1)`