---
title: 239. Sliding Window Maximum
tags:  
    - Sliding Window
    - monotonic queue
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/sliding-window-maximum/)

## solution
- time out  
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret, window;
        int n = nums.size();
        for(int i=0;i<n;++i){
            window.push_back(nums[i]);
            if(window.size()>k) window.erase(window.begin());
            if(window.size() == k){
                int mx = INT_MIN;
                for(int w:window) mx = max(w, mx);
                ret.push_back(mx);
            }
        }
        return ret;
    }
};
```

- monotonic queue 
```c++
class MonotonicQueue{
private:
    deque<int> dq;
public:
    int max(){
        return dq.front();
    }
    void push(int n){
        while(!dq.empty() && dq.back()<n){
            dq.pop_back();
        }
        dq.push_back(n);
        
    }
    void pop(int n){
        if( n== dq.front()) dq.pop_front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue mq;
        vector<int> ret;
        int n = nums.size();
        for(int i=0;i<n;++i){
            mq.push(nums[i]);
            if(i>k-1) mq.pop(nums[i-k]);
            if(i>=k-1) ret.push_back(mq.max());                  
        }
        return ret;
    }
};

```

## analysis
 
- time complexity `O(n)`
- space complexity `O(k)`