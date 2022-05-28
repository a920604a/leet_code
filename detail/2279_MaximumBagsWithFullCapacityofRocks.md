---
title: 2279. Maximum Bags With Full Capacity of Rocks
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/)
## solution
```c++
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int n = rocks.size(), ret = 0;
        vector<int> temp(n,0), vec;
        for(int i=0;i<n;++i){
            temp[i] = max(0, capacity[i] - rocks[i] );
            if(temp[i]>0)  vec.push_back(temp[i]);
            else ret++;
        }
        int a = additionalRocks, i=0;
        sort(vec.begin(), vec.end());
        while(i<vec.size() && a - vec[i]>=0){
            a-=vec[i++];
            ret++;
        }
        return ret;
        
    }
};
```

```c++
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        for(int i=0;i<n;++i){
            capacity[i] = max(0, capacity[i] - rocks[i] );
        }
        sort(capacity.begin(), capacity.end());
        int i = 0;
        while(i<n &&capacity[i] == 0 ) i++;
        int ret = i;
        while(i<n && additionalRocks-capacity[i]>=0){
            additionalRocks-=capacity[i++];
            ret++;
        }
        return ret;
        
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)` `O(1)`