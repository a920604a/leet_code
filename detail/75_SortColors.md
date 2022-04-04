---
title: 75. Sort Colors
tags:
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/sort-colors/)

## solution
- sorting
```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        return sort(nums.begin(),nums.end());
    }
};

```
#### option 1 - STL to store
```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, seconds = 0;
        for(int n:nums){
            if(n==0) zeros++;
            else if(n==1) ones++;
            else seconds++;
        }
        int i=0, n = nums.size();
        while(i<n && zeros>0){nums[i++] = 0;zeros--;}
        while(i<n && ones>0){nums[i++] = 1;ones--;}
        while(i<n && seconds>0){nums[i++] = 2;seconds--;}
        
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
        int slow = 0, fast = 0, n= nums.size();
        while(fast < n){
            if(nums[fast]==0) swap(nums[fast], nums[slow++]);
            fast++;
        }
        fast = slow;
        while(fast < n){
            if(nums[fast]==1) swap(nums[fast], nums[slow++]);
            fast++;
        }
        
    }
};
```
#### option 3 Two Pointer , One Pass
```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() , red = 0, blue = n-1;
        for(int i=0;i<=blue;++i){
            if(nums[i] == 0) swap(nums[i], nums[red++]);
            else if(nums[i]==2) swap(nums[i--], nums[blue--]);
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
- option 3
    - time complexity `O(n)`
    - space complexity `O(1)`