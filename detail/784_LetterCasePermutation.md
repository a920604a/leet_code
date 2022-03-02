---
title: 784. Letter Case Permutation

tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/letter-case-permutation/)

## solution
```c++
class Solution {
public:
    vector<string> ret;
    void traverse(string s, string path,int l){
        
        if(path.size() == s.size()){
            ret.push_back(path);
            return;
        }
        
        for(int i=l;i<s.size() ; ++i){
            
            // 因為只會有大小寫與數字
            if(s[i] >='0' && s[i]<='9'){
                path.push_back(s[i]);
                traverse(s, path, i+1);
                path.pop_back();
                
            }
            // if(( s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            else{
                // 選擇小寫
                path.push_back(tolower(s[i]));
                traverse(s, path, i+1);
                path.pop_back();
                
                // 選擇大寫
                path.push_back(toupper(s[i]));
                traverse(s, path, i+1);
                path.pop_back();
            }      
        }
        
    }
    vector<string> letterCasePermutation(string s) {
        
        string path;
        traverse(s, path, 0);
        return ret;
        
    }
};
```