---
title: 977. Squares of a Sorted Array
tags:  
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/squares-of-a-sorted-array/)

## solution

#### option 1
```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int & a:nums) a=a*a;
        sort(nums.begin(), nums.end());
        return nums;
    }
};
```

#### option 2 - Two Pointers
利用雙索引，去比較左右索引對應到的數字的平方，比較大小。

```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), l=0, r = n-1;
        vector<int>ret(n,0);
        for(int i=n-1;i>-1;--i){
            if(nums[l]*nums[l] > nums[r]*nums[r]){
                ret[i] = nums[l]*nums[l];
                l++;
            }
            else{
                ret[i] = nums[r]* nums[r];
                r--;
            }
        }
        return ret;
    }
};
```
- other version
```c++
vector<int> ret(nums.size(),0);
int l = 0,r = nums.size()-1;
int k =nums.size()-1;
while(l<=r){
    if(abs(nums[l])>=abs(nums[r])) ret[k--] =pow(nums[l++],2);
    else{
        ret[k--] = pow(nums[r--],2);
    }
}
return ret;
```

## analysis
- option 1
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`