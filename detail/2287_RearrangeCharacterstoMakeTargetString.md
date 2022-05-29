---
title: 2287. Rearrange Characters to Make Target String
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/rearrange-characters-to-make-target-string/)
## solution
```c++
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> vec(26,0);
        for(char c:s) vec[c-'a']++;
        int count = 0 ;
        for(int _ = 0; _ < s.size()/target.size() ; ++_){
            for(char a:target){
                if(vec[a-'a'] < 1) return count;
                vec[a-'a']--;
            }
            count++;
        }
        return count;
    }
};
```

## analysis
- target complexity `O(nm)`
- space complexity `O(1)`