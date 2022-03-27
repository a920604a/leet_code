---
title: 1337. The K Weakest Rows in a Matrix
tags:  
    - Binary Search
    - Heap
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/)
## solution 
#### option 1 - Binary Search
```c++
class Solution {
public:
    int BinarySearch(vector<int> & nums){
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == 0)  r = mid-1;
            else l = mid+1;
        }
        if(l<0) return 0;
        return l+1;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // binary search
        int n = mat.size();
        vector<pair<int,int> > ret;
        for(int i=0;i<n;++i){
            int count = BinarySearch(mat[i]);
            ret.push_back({count, i});
        }
        sort(ret.begin(), ret.end(), [](const auto &a, const auto &b){
            if(a.first==b.first) return a.second<b.second;
            else return a.first<b.first;
        });
        vector<int> ans;
        for(int i=0;i<k;++i) ans.push_back(ret[i].second);
        return ans;
    }
};
```

## anslysis
- time complexity `O(nlogn)`
- space complexity `O(n)`