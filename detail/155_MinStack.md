---
title: 155. Min Stack
tags:  
    - stack
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/min-stack/)

## solution
```c++
class MinStack {
private:
    stack<int> sta, minsta;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        sta.push(val);
        // 單調遞減stack
        if(minsta.empty()) minsta.push(val);
        else if(!minsta.empty() && minsta.top()>=val ) minsta.push(val);
    }
    
    void pop() {
        int t = sta.top(); sta.pop();
        if(t == minsta.top()) minsta.pop();
        
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return minsta.top();
    }
};
```