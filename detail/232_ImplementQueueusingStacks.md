---
title: 232. Implement Queue using Stacks

tags:  
    - stack
    - queue
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/implement-queue-using-stacks/)

## solution
```c++
class MyQueue {
private:
    stack<int> sta;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        sta.push(x);
    }
    
    int pop() {
        stack<int> temp;
        int ret , size = sta.size()-1;
        while(size--){
            temp.push(sta.top());
            sta.pop();
        }
        ret = sta.top();
        sta.pop();
        
        while(!temp.empty()) { sta.push(temp.top());temp.pop();}
        
        return ret;
        
    }
    
    int peek() {
        stack<int> temp;
        int ret ;
        while(!sta.empty()){
            ret = sta.top();
            sta.pop();
            temp.push(ret);
        }
        while(!temp.empty()) { sta.push(temp.top());temp.pop();}
        
        return ret;
    }
    
    bool empty() {
        return sta.empty();
    }
};


```

## analysis
- pop and peek operation time complexity `O(n)`
- space complexity `O(n)`