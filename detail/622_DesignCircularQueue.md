---
title: 622. Design Circular Queue
tags:
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/design-circular-queue/)
## solution
利用初始化陣列 `vector<int>(k,-1);`，如果數值是-1，代表該空間為空，可以assign

```c++
class MyCircularQueue {
private:
    vector<int> nums;
    int front , back, cap ;
public:
    MyCircularQueue(int k) {
        nums = vector<int>(k,-1);
        front = 0;
        back = 0;
        cap = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        nums[back] = value;
        back = (back+1)%cap;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        nums[front] = -1;
        front = (front+1)%cap;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return nums[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return nums[(back-1+cap)%cap];
    }
    
    bool isEmpty() {
        return nums[front] == -1 && (back== front);
        
    }
    
    bool isFull() {
        return nums[back]!=-1 && (back == front);
        
    }
};
```