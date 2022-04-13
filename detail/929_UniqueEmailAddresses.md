---
title: 929. Unique Email Addresses
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/unique-email-addresses/)
## solution 
```c++
class Solution {
public:
    string process(string str){
        string local_name , domain_name;
        int i = 0;
        while(str[i]!='@'){
            if(str[i]=='+') break;
            else if(str[i]!='.') local_name += str[i];
            i++;
        }
        while(str[i]!='@') i++;
        i++;
        while(i<str.size()) domain_name+=str[i++];
        
        string ans = local_name + "@"+domain_name;
        return ans;
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(string strs:emails) s.insert(process(strs));
        return s.size();
        
    }
};
```
## analysis 
- time complexity `O(nm)`
- space complexity `O(nm)`