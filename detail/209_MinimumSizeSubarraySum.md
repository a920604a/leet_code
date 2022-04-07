---
title: 209. Minimum Size Subarray Sum
tags: 
    - Sliding window
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-size-subarray-sum/)


## solution
#### option 1 - brute force 
```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() , len = n+1 ;
        for(int i=0;i<n;++i){
            int cand = 0;
            for(int j=i;j<n && j<=i+len;++j){
                cand+=nums[j];
                if(cand >=target){
                    len = min(j-i+1, len);
                    break;
                }
            }
        }
        return len==n+1?0:len;
        
    }
};
```
#### option 2 - sliding window
```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window
        int window = 0;
        int n = nums.size();
        int l=0, r = 0;
        int len = INT_MAX;
        while(r<n){
            int last = nums[r++];
            
            window+=last;
            while(window>=target){
                len =min(len, r-l);
                
                int first = nums[l++];
                window-=first;             
            }
        }
        return len==INT_MAX?0:len;
    }
};
```
#### option 3 - Binary Search
```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        //  2   5   6   8   12  15
        // prefix sum + binary 
        nums.insert(nums.begin(), 0);
        int total = 0, n = nums.size(), len = n+1;
        vector<int> prefix(n,0);
        for(int i=0;i<n;++i){
            total+=nums[i];
            prefix[i] = total;
        }
        for(int i=0;i<n-1;++i){
            int l = i+1, r = n-1;
            while(l<=r){
                int mid = l + (r-l)/2;
                int eval = prefix[mid] - prefix[i];
                if(eval == target){
                    len = min(len, mid-i);
                    break;
                }
                else if(eval < target) l = mid+1;
                else r = mid-1;
            }
            if(l<n && prefix[l] - prefix[i] >=target){
                len = min(l-i, len);
            }
        }
        return len==n+1?0:len;        
    }
};
```
```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        //  2   5   6   8   12  15
        // prefix sum + binary 
        nums.insert(nums.begin(), 0);
        int total = 0, n = nums.size(), len = n+1;
        vector<int> prefix(n,0);
        for(int i=0;i<n;++i){
            total+=nums[i];
            prefix[i] = total;
        }
        for(int i=0;i<n-1;++i){
            // right bounder
            int l = i+1, r = n-1;
            int eval = target + prefix[i];
            while(l<=r){
                int mid = l + (r-l)/2;
                if(prefix[mid] >= eval) r = mid-1;
                else l = mid+1;
            }
            if(l==n) continue;
            len = min(l-i, len);
        }
        return len==n+1?0:len;        
    }
};
```
## analysis
- option 1
    - time complexity `O(n*n)`
    - space complexity `O(1)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 3
    - time complexity `O(nlogn)`
    - space complexity `O(n)`