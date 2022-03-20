---
title: 895. Maximum Frequency Stack
tags:  
    - hash table
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/maximum-frequency-stack/)

## solution

```c++
class FreqStack {
private:
    unordered_map<int ,int> valToFreq;
    unordered_map<int ,stack<int>> freqToVals; 
    int maxFreq ;   
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        
        int freq = valToFreq[val];
        valToFreq[val]++;
        maxFreq = max(maxFreq, freq);
        freqToVals[freq].push(val);        
    }
    
    int pop() {
        stack<int> &vals = freqToVals[maxFreq];
        int ret = vals.top();
        valToFreq[ret]--;
        vals.pop();
        if(vals.empty()) maxFreq--;
        
        return ret;
        
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
```