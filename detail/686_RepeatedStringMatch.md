---
title: 686. Repeated String Match
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/repeated-string-match/)


## solution
先重複a多次，直到達到b長度，在遍歷aa尋找是否有字串相符

```c++
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        
        int m = b.size(), repeat = 1;
        string aa = a;
        while(aa.size() <m){
            aa+=a;
            repeat++;
        }
        int n = aa.size();
        if (aa.find(b) != string::npos) return repeat;
        aa += a;
        return (aa.find(b) != string::npos) ? repeat + 1 : -1;
  
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`