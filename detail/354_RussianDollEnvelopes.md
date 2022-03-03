---
title: 354. Russian Doll Envelopes
tags:  
    - dp
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/russian-doll-envelopes/)

## solution 

#### option 1 - dp
可能會time out

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        //  2   3   5   4   5   5   6   7   8
        
        //  3   4   7   4
        //  
        // dp base method => time out
        int n = nums.size(), ret = 1;
        vector<int> dp(n, 1);
        for(int i=1;i<n;++i){
            for(int j = 0;j<i;++j){
                if(nums[i]> nums[j]) dp[i] = max(1+dp[j], dp[i]);
                ret = max(ret, dp[i]);
            }
        }
        return ret;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 先確保每個vector<int> 第一元素是升序排列，第一元素相同情況下，第二元素降序排列
        // 在創建一個vector<int> 為 陣列中每個元素的第二元素(剛降序的個果)，再娶嘴長遞增子陣列
        
        //  [2,3] [5,4] [6,7] [6,4]
        // [[1,2],[2,3],[3,5],[3,4],[4,5],[5,5],[5,6],[6,7],[7,8]]
        // [[2,100],[3,200],[4,300],[5,500],[5,400],[5,250],[6,370],[6,360],[7,380]]
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int> nums;
        for(vector<int> v:envelopes) nums.push_back(v[1]);
        return lengthOfLIS(nums);
    }
};
```

#### option 2 - Binary Search

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        //  2   3   5   4   5   5   6   7   8
        
        //  3   4   7   4
        //  
        
        int piles = 0;
        vector<int> top(nums.size(),0);
        for(int poker:nums){
            int l = 0, r = piles;
            while(l<r){
                int mid = l +(r-l)/2;
                if(top[mid] == poker) r = mid;
                else if(top[mid] < poker) l = mid+1;
                else r = mid;
            }
            if(l==piles) piles++;;
            top[l] = poker;
        }
        return piles;
        
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 先確保每個vector<int> 第一元素是升序排列，第一元素相同情況下，第二元素降序排列
        // 在創建一個vector<int> 為 陣列中每個元素的第二元素(剛降序的個果)，再娶嘴長遞增子陣列
        
        //  [2,3] [5,4] [6,7] [6,4]
        // [[1,2],[2,3],[3,5],[3,4],[4,5],[5,5],[5,6],[6,7],[7,8]]
        // [[2,100],[3,200],[4,300],[5,500],[5,400],[5,250],[6,370],[6,360],[7,380]]
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int> nums;
        for(vector<int> v:envelopes) nums.push_back(v[1]);
        return lengthOfLIS(nums);
    }
};

```


## analysis

- option 1 - dp
    - time complexity `O(n^2)` 
    - space complexity `O(n^2)`
- option 2 - binary search
    - time complexity `O(nlogn)`
    - space complexity `O(n)`
