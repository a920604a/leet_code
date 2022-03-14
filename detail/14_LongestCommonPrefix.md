---
title: 14. Longest Common Prefix
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/longest-common-prefix/)


## solution
```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret ;
        int n = strs.size();
        for(int i=0;i<strs[0].size(); ++i){
            int count = 1;
            for(int j = 1;j<n;++j){
                if(strs[0][i] == strs[j][i]) count++;
                else break;
            }
            if(count==n) ret+=strs[0][i];
            else return ret;
        }
        return ret;
        
    }
};
```


## analysis
- time complexity `O(nm)`
- space complexity `O(n)`