---
title: 870. Advantage Shuffle
tags:  
    - sorting
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/advantage-shuffle/)


## solution

將nums1 排序，將nums2 `{nums2[i], i} `push 進heap，每次從heap 派出最大，與`nums1[r]` 比較大小，如果大於等於`nums1[r]`，打不過，那就派出最爛的`nums1[l]`，反之派出最強的`nums[r]`

```c++
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        auto cmp = [](pair<int,int> & a, pair<int,int>& b){
            return a.first<b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp) > pq(cmp);
        for(int i=0;i<nums2.size();++i) pq.push(make_pair(nums2[i], i) );
        
        sort(nums1.begin(),nums1.end());
        vector<int>ret(nums1.size(), 0);
        int l = 0, r = nums1.size()-1;
        while(!pq.empty()){
            int maxVal = pq.top().first, i = pq.top().second;
            pq.pop();
            if(maxVal >= nums1[r]){
                ret[i] = nums1[l++];
            }
            else{
                ret[i] = nums1[r--];
            }
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`