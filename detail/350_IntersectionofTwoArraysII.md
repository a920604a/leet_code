---
title: 350. Intersection of Two Arrays II
tags:  
    - sorting
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

## solution

#### option 1 - hash table
```c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int> ret;
        for(int n:nums1) mp[n]++;
        for(int n:nums2){
            if(mp.find(n)!=mp.end() && mp[n]!=0){
                mp[n]--;
                ret.push_back(n);
            }
        }
        return ret;
    }
};
```

#### option 2 - improve hash table
```c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq(10001,0), ret;
        for(int n:nums1) freq[n]++;
        for(int n:nums2){
            if(freq[n]>0){
                ret.push_back(n);
                freq[n]--;
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int l=0,r=0, n=nums1.size(), m = nums2.size();
        while(l<n && r<m){
            if(nums1[l] == nums2[r]) {
                ret.push_back(nums1[l]);
                // while(l+1<n && nums1[l] == nums1[l+1]) l++;
                // while(r+1<m && nums2[r] == nums2[r+1]) r++;
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

## analysis
- option 1
    - time complexity `O(nlogn)`
    - space complexity `O(n)`
- option 1
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 3 - sorting
    - time complexity `O(nlogn)`
    - space complexity `O(1)`

