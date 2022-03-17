---
title: 75. Sort Colors
tags:
    - Randomized
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/sort-colors/)

## solution
#### option 1 - STL to store
```c++

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 統計0,1,(2) 個數
        int c0 = 0, c1 = 0, n = nums.size();
        for(int i:nums){
            if(i==0) c0++;
            else if(i==1) c1++;
        }
        // assign value
        int i=0;
        while(c0>0 && i<n){
            nums[i++] = 0;
            c0--;
        }
        while(c1>0 && i<n){
            nums[i++] = 1;
            c1--;
        }
        while(i<n) nums[i++] = 2;
        
    }
};
```

#### option 2 - Two Pointers
```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        
        // because of only three colors
        // two pass
        // slow fast pointer to swap
        // setting zero
        int slow = -1, fast = 0, n = nums.size();
        while(fast<n){
            if(nums[fast] == 0){
                swap(nums[++slow], nums[fast]);
            }
            fast++;
        }
        fast = slow+1;
        while(fast<n){
            if(nums[fast] == 1) swap(nums[++slow], nums[fast]);
            fast++;
        }
        
        
    }
};
```
## analysis
- option 1
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`