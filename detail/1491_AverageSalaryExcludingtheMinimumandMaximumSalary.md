---
title: 1491. Average Salary Excluding the Minimum and Maximum Salary
tags: 
    - sorting
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/)


## solution
#### option 1 - sort
```c++
class Solution {
public:
    double average(vector<int>& salary) {
        // sorting
        sort(salary.begin(), salary.end());
        double total = 0, n=salary.size();
        for(int i=1;i<n-1;++i) total+=salary[i];
        return total/(n-2);
        
    }
};
```
#### option 2
```
class Solution {
public:
    double average(vector<int>& salary) {
        
        double total = 0, n=salary.size();
        int mx = salary[0], mn = salary[1];
        for(int s:salary){
            total+=s;
            mx = max(mx,s);
            mn = min(mn, s);
        }
        total-= (mn+mx);
        return total/(n-2);
    }
};
```
## analysis
- option 1
    - time complexity `O(nlogn)`
- option 2
    - time complexity `O(n)`