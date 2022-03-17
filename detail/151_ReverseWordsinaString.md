---
title: 151. Reverse Words in a String
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/reverse-words-in-a-string/)

## solution

#### option 1 
```c++
class Solution {
public:
    vector<string> split(string s){
        vector<string> ret;
        string path;
        for(char c:s){
            if(c==' '){
                if(!path.empty()) ret.push_back(path);
                path="";
            }
            else path+=c;
        }
        if(!path.empty()) ret.push_back(path);
        return ret;
    }
    string reverseWords(string s) {
        vector<string> ret = split(s);
        reverse(ret.begin(), ret.end());
        string ans ;
        for(string str:ret) ans+=str+" ";
        return ans.substr(0, ans.size()-1);   
    }
};
```

#### option 2 
```c++
class Solution {
public:
    string reverseWords(string s) {
        string ret;
        int i= 0;
        for(int j=0;j<s.size() ; ++j){
            if(s[j] == ' '){
                reverse(s.begin()+i, s.begin()+j);
                // avoid extra space
                while(j<s.size() && s[j+1] == ' ') j++;
                i = j+1;
            }
        }
        reverse(s.begin()+i, s.end());
        // trim
        int l =0;
        while(l<s.size() && s[l]==' ') l++;
        s= s.substr(l, s.size()-l);
        
        reverse(s.begin(), s.end());
        // trim
        l =0;
        while(l<s.size() && s[l] ==' ') l++;
        s= s.substr(l, s.size()-l);
        
        for(char c:s){
            if(ret.back() == ' ' && c== ' ') continue;
            ret+=c;   
        }
        return ret;
        
    }
};
```

## analysis
- option 1
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n^2)`
    - space complexity `O(1)`


