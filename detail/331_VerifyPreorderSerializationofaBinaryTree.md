---
title: 331. Verify Preorder Serialization of a Binary Tree
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/)

## solution
```c++
class Solution {
public:
    vector<string> split(string words){
        vector<string> pre;
        string cur;
        for(char c:words){
            if(c==','){
                pre.push_back(cur);
                cur.clear();
            }
            else{
                cur+=c;
            }
        }
        if(!cur.empty()) pre.push_back(cur);
        return pre;
    }
    bool isValidSerialization(string preorder) {
        
        vector<string> pre = split(preorder);
        int num_child = 1;
        for(string str:pre){
            num_child--;
            if(num_child<0) return false;
            if(str!="#"){
                num_child+=2;
            }
        }
        return num_child==0;   
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`