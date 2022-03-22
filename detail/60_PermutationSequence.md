---
title: 60. Permutation Sequence
tags:  
    - math
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/permutation-sequence/)

## solution
#### option 1 
```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 先從右往左找到，非遞增的位置
        int n = nums.size();
        int j = n-1;
        while(j>0 && nums[j-1] >= nums[j] ) j--;
        if(j==0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int pivot=j-1;
        int bigger = n-1;
        while(bigger > pivot && nums[bigger] <= nums[pivot]) bigger--;
        swap(nums[pivot], nums[bigger]);
        reverse(nums.begin()+pivot+1, nums.end());
    }
    
    string getPermutation(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=n;++i){
            // ans+=to_string(i);
            ans.push_back(i);
        }
        while(--k) nextPermutation(ans);
        string str ;
        for(int i:ans) str+=to_string(i);
        return str;
    }
};
```
#### option 2 - *math
```c++
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;++i) nums.push_back(i);
        
        k--;
        int mod = 1;
        for(int i=1;i<=n;i++) mod = mod*i;
        string ret;
        for(int i=0;i<n;++i){
            mod = mod/(n-i);
            int idx = k/mod;
            k=k%mod;
            ret+=to_string(nums[idx]);
            nums.erase(nums.begin()+idx);
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(kn)`
- space complexity `O(1)`