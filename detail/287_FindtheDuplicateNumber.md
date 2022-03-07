---
title: 287. Find the Duplicate Number

tags:  
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-the-duplicate-number/)

給定一維陣列，找出重複一遍的數字，其餘數字皆為不重複。不能修改原陣列。

## solution


#### option 1 - Two Pointers
- 利用兩個索引，一個跑的慢，一個跑得快，並找出相交位置。找到後一個從原點開始再跑，另一個從相遇地點開始跑。在遇到則為答案

```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        //  1   3   4   2   2   
        
        //slow 0 -> 1 -> 3 -> 2 -> 4 -> 2 -> 4
        //fast 0 -> 3 -> 4 -> 4 -> 4
        
        //slow 4 -> 2 -> 4 -> 2 
        //fast 0 -> 1 -> 3 -> 2 
        int slow =0, fast = 0;
        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast) break;
        }
        slow = 0;
        while(1){
            slow = nums[slow];
            fast = nums[fast];
            if(slow==fast) return slow;
        }
        return -1;   
    }
};
```

#### option 2 - index

```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;++i){
            int idx = abs(nums[i])-1;
            // number has visited
            if(nums[idx]<0) return idx+1;
            else nums[idx] *=-1;
        }
        return -1;   
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
