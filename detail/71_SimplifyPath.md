---
title: 71. Simplify Path
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/simplify-path/)


## solution 
先用split 切分成個字串，在判斷字串是否為"." 或是 ".."

```c++
class Solution {
public:
    vector<string> split(string str , char del ){
        vector<string> ret;
        string path ;
        for(char c:str){
            if(c==del){
                if(!path.empty()) ret.push_back(path);
                path="";
            }
            else path+=c;
        }
        if(!path.empty()) ret.push_back(path);
        return ret;
    }
    string simplifyPath(string path) {
        vector<string> str = split(path, '/');
        vector<string> ans;
        for(string tmp : str){
            if(tmp.empty()) continue;
            if(tmp == ".") continue;
            else if(tmp ==".."){
                if(!ans.empty()) ans.pop_back();
            }
            else ans.push_back(tmp);
        }
        string ret;
        for(string c:ans) ret+="/"+c;
        return ret.empty()?"/":ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`