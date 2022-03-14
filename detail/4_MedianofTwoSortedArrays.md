---
title: 4. Median of Two Sorted Arrays
tags:  
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)


## solution
#### option 1 - cheat merge sort
```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ret(n+m,0);
        int l =0, r = 0, i = 0;
        while(l<n && r<m){
            if(nums1[l] < nums2[r]) ret[i++] = nums1[l++];
            else ret[i++] = nums2[r++];
        }
        while(l<n) ret[i++] = nums1[l++];
        while(r<m) ret[i++] = nums2[r++];
        if((n+m)%2==1) return ret[(n+m)/2];
        else return (double)(ret[(n+m)/2]+ret[(n+m)/2-1])/2.0;      
    }
};
```
#### option 2 - *Binary Search
```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),  m = nums2.size();
        int len = n+m;
        if(n>m) return findMedianSortedArrays(nums2, nums1);
        
        if(n==0) return (nums2[(m-1)/2] + nums2[m/2]) / 2.0;
        
        int l = 0, r = n;
        while(l<=r){
            // i 指向nums1 中間的索引，j 指向nums2 中間的索引
            int i = l + (r-l)/2;
            int j = len/2-i;
            
            
            // 設定搜尋區間
            int L1 = (i==0)?INT_MIN:nums1[i-1];
            int R1 = (i==n)?INT_MAX:nums1[i];
            int L2 = (j==0)?INT_MIN:nums2[j-1];
            int R2 = (j==m)?INT_MAX:nums2[j];
            
            if(L1 > R2) r = i - 1;
            else if(L2 > R1) l = i+1;
            else{
                if(len%2==1) return min(R1, R2);
                else return (max(L1, L2) + min(R1, R2)) / 2.0; 
            }
            
        }
        return -1;
        
    }
};

```
## analysis
- option 1 
    - time complexity `O(n+m)`
    - space complexity `O(n+m)`
- option 2 
    - time complexity `O(log(m+n))`
    - space complexity `O(1)`