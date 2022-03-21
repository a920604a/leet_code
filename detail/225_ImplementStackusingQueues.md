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


#### option 1
```c++
class MyStack {
private:
    queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(empty()) q1.push(x);
        else{
            if(q1.size()>0){
                q2.push(x);
                int size = q1.size();
                while(size >0){
                    q2.push(q1.front());
                    q1.pop();
                    size--;
                }
            }
            else if(q2.size() > 0){
                q1.push(x);
                int size = q2.size();
                while(size>0){
                    q1.push(q2.front());
                    q2.pop();
                    size--;
                }
            }
        }
        
    }
    
    int pop() {
        if(q1.size()>0) {
            int t = q1.front();
            q1.pop();
            return t;
        }
        else if(q2.size()>0) {
            int t = q2.front();
            q2.pop();
            return t;
        }
        return 0;
    }
    
    int top() {
       if(q1.size()>0) return q1.front();
        else if(q2.size()>0) return q2.front();
        return 0; 
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

```
## analysis
- pop and top operation time complexity `O(n)`
- space complexity `O(n)`