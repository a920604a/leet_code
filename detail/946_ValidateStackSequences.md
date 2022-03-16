---
title: 946. Validate Stack Sequences
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/validate-stack-sequences/)

## solution

```c++
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), i=0, j=0;
        stack<int> sta;
        while(i<n && j<n){
            if(pushed[i] == popped[j]){i++;j++;}
            else sta.push(pushed[i++]);
            // 檢查當前j 指向的值是否為stack.top()
            while(j<n && !sta.empty() &&  sta.top() == popped[j]){
                sta.pop();
                j++;
            }
        }
        return j==n && sta.empty();
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`