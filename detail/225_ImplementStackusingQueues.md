---
title: 225. Implement Stack using Queues
tags:  
    - stack
    - queue
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/implement-stack-using-queues/)

## solution
```c++
class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        
    }
    
    int pop() {
        queue<int> temp;
        int ret ;
        int size = q.size();
        size--;
        while(size--){
            temp.push(q.front());
            q.pop();
        }
        ret = q.front();
        q.pop();
        
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        return ret;
    }
    
    int top() {
        queue<int> temp;
        int ret ;
        int size = q.size();
        while(size--){
            ret = q.front();
            temp.push(q.front());
            q.pop();
        }
        
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        return ret; 
        
    }
    
    bool empty() {
        return q.empty();
        
    }
};

```

## analysis
- pop and top operation time complexity `O(n)`
- space complexity `O(n)`