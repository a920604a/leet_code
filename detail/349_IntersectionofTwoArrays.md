---
title: 349. Intersection of Two Arrays
tags:  
    - sorting
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/intersection-of-two-arrays/)

## solution
#### option 1 - set
```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // set
        unordered_set<int> s, ret;
        for(int n :nums1) s.insert(n);
        for(int n :nums2) {
            if(s.find(n)!=s.end()) ret.insert(n);
        }
        return vector<int>(ret.begin(), ret.end());   
    }
};
```
#### option 2 - improve set
```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq(10001,0), ret;
        for(int n:nums1) freq[n]++;
        for(int n:nums2){
            if(freq[n]>0){
                ret.push_back(n);
                freq[n]=0;
            }
        }
        return ret;
        
    }
};
```
#### option 3 - sorting
```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int l=0,r=0, n=nums1.size(), m = nums2.size();
        while(l<n && r<m){
            if(nums1[l] == nums2[r]) {
                ret.push_back(nums1[l]);
                // de duplicate
                while(l+1<n && nums1[l] == nums1[l+1]) l++;
                while(r+1<m && nums2[r] == nums2[r+1]) r++;
                l++;
                r++;
            }
            else{
                if(nums1[l]<nums2[r]) l++;
                else r++;
            }
        }
        return ret;
    }
};
```
#### option 4 - binary search

```c++
class Solution {
public:
    bool BinarySearch(vector<int>& nums, int target){
        int l =0, r = nums.size();
        while(l<r){
            int mid = l +(r-l)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) l = mid+1;
            else r = mid;
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        sort(nums1.begin(), nums1.end());
        for(int n:nums2){
            if(BinarySearch(nums1, n)) s.insert(n);
        }
        return vector<int>(s.begin(), s.end());
    }
};
```

## analysis
- option 1
    - time complexity `O(nlogn)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 3 - sorting
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- option 4 - binary search
    - time complexity `O(nlogn)`
    - space complexity `O(1)`