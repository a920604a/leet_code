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
#### option 1
```c++
class MyQueue {
private:
    stack<int>temp;
    stack<int>value;
public:
    MyQueue() {
        
    }
    void push(int x) {
        if(value.empty()) value.push(x);
        else{
            while(!value.empty()){
                temp.push(value.top());
                value.pop();
            }
            value.push(x);
            while(!temp.empty()){
                value.push(temp.top());
                temp.pop();
            }
        }
        
    }
    
    int pop() {
        int ret = value.top(); 
        value.pop();
        return ret;
    }
    
    int peek() {
        return value.top();
    }
    
    bool empty() {
        return value.empty();
    }
};

```
## analysis
- pop and peek operation time complexity `O(n)`
- space complexity `O(n)`