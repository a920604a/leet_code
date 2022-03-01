---
title: 1790. Check if One String Swap Can Make Strings Equal

categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)

## solution

```c++
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), count = 0;
        vector<int> ret(26,0);
        for(int i=0;i<n;++i){
            if(s1[i]!=s2[i]) count++;
            if(count>2) return false;
            ret[s1[i]-'a']++;
            ret[s2[i]-'a']--;
        }
        if(ret != vector<int>(26,0)) return false;
        return true;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`
