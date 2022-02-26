---
title: 414. Third Maximum Number
tags:
    - heap
    - math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)


## solution
#### option 1 - heap

```c++
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> pq;
        unordered_set<int> s;
        for(int n :nums){
            if(s.find(n)==s.end()) pq.push(n);
            s.insert(n);
        }
        if(pq.size() <3) return pq.top();
        pq.pop();
        pq.pop();
        return pq.top();
    }
};
```

#### option 2 - Math
```c++
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = 0, second = 0, third = 0;
        long max_1 =INT_MIN, max_2 =LONG_MIN, max_3 = LONG_MIN;
        for(int n:nums){
            if(n==max_1 || n==max_2 || n== max_3) continue;
            
            if(n>max_1){
                max_3 = max_2;
                max_2 = max_1;
                max_1 = n;
            }
            else if(n>max_2) {
                max_3 = max_2 ;
                max_2 = n;
            }
            else if(n>max_3){
                max_3 = n;
            }
        }
        
        return max_3==LONG_MIN?max_1:max_3;
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`