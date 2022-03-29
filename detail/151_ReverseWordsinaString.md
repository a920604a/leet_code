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
    string reverseWords(string s) {
        vector<string> ret;
        string cur;
        int n = s.size();
        for(int i=0;i<n ; ++i){
            char c =s[i];
            if(c == ' '){
                if(!cur.empty()) ret.push_back(cur);
                cur.clear();
                while(i<n && s[i+1] ==' ') i++;
            }
            else cur+=c;
        }
        if(!cur.empty()) ret.push_back(cur);
        reverse(ret.begin(), ret.end());
        string ans;
        for(int i=0;i<ret.size() ; ++i){
            ans+=ret[i];
            if(i!=ret.size()-1) ans+=' ';
        }
        return ans;
        
    }
};
```

#### option 2 
```c++
class Solution {
public:
    string reverseWords(string s) {
        
        int pre = 0, n = s.size();
        for(int i=0;i< n; ++i){
            char c = s[i];
            if(c==' '){
                reverse(s.begin()+pre, s.begin()+i);
                // avoid extra space
                while(i+1<n && s[i+1] ==' ') i++;
                pre = i+1;
            }
        }
        
        reverse(s.begin()+pre, s.end());
        reverse(s.begin(), s.end());
        // trim
        int l=0, r = s.size()-1;
        while(l<r && s[l] == ' ') l++;
        while(l<r && s[r] ==' ') r--;
        s = s.substr(l, r-l+1);
        string ret;
        for(char c:s){
            if(ret.back() ==' ' &&  c==' ') continue;
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
    - time complexity `O(n)`
    - space complexity `O(1)`


