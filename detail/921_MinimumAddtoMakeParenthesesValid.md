---
title: 921. Minimum Add to Make Parentheses Valid
tags:  
    - greedy
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

## solution

#### option 1 - stack
```c++
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> sta;
        int count=0;
        for(char c:s){
            if(c=='('){
                sta.push(c);
            }
            else{
                // 右括號多於左括號
                if(sta.empty()) count++;
                else sta.pop();
            }
        }
        // 為匹配的左括號數量
        count+=sta.size();
        return count;
    }
};

```
#### option 2 
```c++

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int l =0, r = 0, count = 0;
        for(char c:s){
            if(c=='('){
                l++;
            }
            else{
                r++;
                // 拜訪到')' ，檢查之前出現過的 '(' 個數必須一樣
                if(r>l) {
                    count+=(r-l);
                    l+=(r-l);
                }
            }
        }
        // 左括號多於右括號
        if(l>r) count+=(l-r);
        return count;
    }
};
```

#### option 3

```c++
class Solution {
public:
    int minAddToMakeValid(string s) {
        // ret : 插入次數，need : 右括號需求量
        int ret = 0, need = 0 ;
        for(char c:s){
            if(c=='('){
                
                need++;
            }
            else{
                need--;
                if(need==-1){
                    ret++;
                    need = 0;
                }
            }
        }
        return ret+need;
    }
};
```
## analysis
- option 1 - stack
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 2 
    - time complexity `O(n)`
    - space complexity `O(1)`