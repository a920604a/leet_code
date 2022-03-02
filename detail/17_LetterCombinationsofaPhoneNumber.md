---
title: 17. Letter Combinations of a Phone Number
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)


## solution

#### option 1 - dfs
```c++
class Solution {
public:
    unordered_map<int, string> dict = {
        {2,"abc"},{3,"def"},
        {4,"ghi"},{5,"jkl"},{6,"mno"},
        {7,"pqrs"},{8,"tuv"},{9,"wxyz"}
        
    };
    vector<string> ret;
    void traverse(string digits, int i, string & path){
        // 終止條件
        if(i == digits.size() ){
            ret.push_back(path);
            return;
        }
        for(char c: dict[digits[i]-'0'] ){
            path+=c;
            traverse(digits, i+1, path);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ret;
        string path;
        traverse(digits, 0, path);
        return ret;
        
        
    }
};
```

#### option 2 - bfs 
```c++
class Solution {
public:
    unordered_map<int, string> dict = {
        {2,"abc"},{3,"def"},
        {4,"ghi"},{5,"jkl"},{6,"mno"},
        {7,"pqrs"},{8,"tuv"},{9,"wxyz"}
        
    };
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret;  
        
        if(digits.empty()) return ret;
        
        queue<string> q;
        int k = 0;
        for(char c:dict[digits[k]-'0']) {
            string temp ;
            temp.push_back(c);
            q.push(temp);
        }
        
        while(!q.empty() && k<digits.size()-1){
            int size = q.size();
            k++;
            for(int i=0;i<size ; ++i){
                string p = q.front();
                q.pop();   
                for(char c:dict[digits[k]-'0']){
                    string temp = p;
                    temp.push_back(c);
                    q.push(temp);
                }
            }
        }
        while(!q.empty()){
            
            string cur = q.front();
            q.pop();
            ret.push_back(cur);
        }
        return ret;
    }
};
```