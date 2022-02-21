---
title: 344. Reverse String
tags:  
    - Two Pointers
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/reverse-string/)

## solution
```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
```
#### option 1 - Two Pointers
```c++
class Solution {
public:
    void swap(char *a, char* b){
        *a = *a^*b;
        *b = *a^*b;
        *a = *a^*b;
    }
    void reverseString(vector<char>& s) {
        int l =0, r=s.size()-1;
        while(l<r) swap(&s[l++], &s[r--]);
    }
};

```

#### option 2 - stack
```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> sta;
        for(char c:s) sta.push(c);
        for(int i=0;i<s.size() ; ++i) {s[i] = sta.top();sta.pop();}
    }
};

```

## analysis
- option 1 - Two Pointers
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 2 - stack
    - time complexity `O(n)`
    - space complexity `O(n)`