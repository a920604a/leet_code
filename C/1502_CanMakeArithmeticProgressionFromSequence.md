---
title: 1502. Can Make Arithmetic Progression From Sequence
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)


## solution

#### option 1 - sorting
```c++
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), diff = arr[1]-arr[0];
        for(int i=1;i<n;++i){
            if(arr[i]-arr[i-1] != diff) return false;
        }
        return true;
    }
};
```
#### option 2
```c++
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size(), mn = INT_MAX, mx = INT_MIN;
        unordered_set<int> s;
        for(int a:arr){
            mn = min(a, mn);
            mx = max(a, mx);
            s.insert(a);
        }
        int diff = (mx-mn)/(n-1), cur = mn;
        while(n--){
            if(s.find(cur)==s.end()) return false;
            cur+=diff;
        }
        return true;
    }
};
```
> unordered_set insert and serach 分攤後時間複雜度都是 `O(1)`
## analysis
- option 1 - sorting
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- option 2 
    - time complexity `O(n)`
    - space complexity `O(n)`