---
title: 2186. Minimum Number of Steps to Make Two Strings Anagram II
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/)


## solution
```c++
class Solution {
public:
    int minSteps(string s, string t) {
        // beacuse only have lowercase English 
        vector<int> ret(26,0);
        for(char c:s) ret[c-'a']++;
        for(char c:t) ret[c-'a']--;
        int count = 0;
        for(int r:ret) count+=(abs(r));
        return count;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`

