---
title: 641. Design Circular Deque
tags:
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/design-circular-deque/)
## solution
- be careful of pointer out of range
```c++
class MyCircularDeque {
private:
    vector<int> nums;
    int cap, front, back;
public:
    MyCircularDeque(int k) {
        cap = k;
        front = back = 0;
        nums = vector<int> (k, -1);
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        front = (front-1+cap)%cap;
        nums[front] = value;
        return true;
        
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        nums[back] = value;
        back = (back+1)%cap;
        return true;
        
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        nums[front] = -1;
        front = (front+1)%cap;
        return true;
        
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        back = (back-1+cap)%cap;
        nums[back] = -1;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return nums[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return nums[(back-1+cap)%cap];
    }
    
    bool isEmpty() {
        return nums[front]==-1 && (back==front);
        
    }
    
    bool isFull() {
        return nums[front]!=-1 && (back==front);
    }
};
```

