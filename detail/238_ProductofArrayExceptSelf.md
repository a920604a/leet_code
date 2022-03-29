---
title: 238. Product of Array Except Self

tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/product-of-array-except-self/)

返回陣列，其元素為其餘元素相乘


## Solution

維護兩個dp，一個從左往右累乘，另一個由右往左累乘
#### option 1
```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int> ret(n,1), left(n,1), right(n,1);
        //          1   2   3   4
        //left      1   1   2   6
        //right     24  12  4   1
        for(int i=1;i<n;++i) left[i] = left[i-1]*nums[i-1];
        for(int i=n-2;i>-1;i--) right[i] = right[i+1]*nums[i+1];
        
        for(int i=0;i<n;++i) ret[i] = left[i]*right[i];
        return ret;
        
    }
};
```

#### option 2

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int> ret(n,1);
        for(int i=n-2;i>-1;--i) ret[i] = nums[i+1]*ret[i+1];
        //      1   2   3   4
        //      24  12  4   1 => ret
        //left  1   1   2   6
        int left = 1;
        for(int i=1;i<n;++i){
            left *= nums[i-1];
            ret[i] = ret[i] * left;
        }
        return ret;
    }
};
```
## analysis
- option 1
    - time complexity `O(n)`
    - speed complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - speed complexity `O(1)`
