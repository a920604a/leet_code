---
title: 295. Find Median from Data Stream
tags:  
    - heap
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)


## solution
```c++
class MedianFinder {
    
private:
    // 需要兩個heap，一個放大於中位數的heap，每次取最小，另一個放小於中位數的heap，每次取最大
    priority_queue<int, vector<int>, greater<int>> down;
    priority_queue<int,vector<int>> up;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(up.size() >= down.size()){
            up.push(num);
            down.push(up.top());
            up.pop();
        }
        else{
            down.push(num);
            up.push(down.top());
            down.pop();
        }
    }
    
    double findMedian() {
        if(up.size() > down.size()) return up.top();
        else if(down.size() > up.size()) return down.top();
        return (up.top() + down.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```
## analysis

- `addNum` time complexity `O(logn)`
- `findMedian` time complexity `O(1)`