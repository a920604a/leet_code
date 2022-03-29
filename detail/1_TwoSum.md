---
title: 1. Two Sum

tags:  
    - hash table
categories: leetcode
comments: false
---




## [problem](https://leetcode.com/problems/two-sum/)

- 一維陣列中找出兩數相加等於target，並返回其索引


## Solution

#### brute force
- 利用兩個index 分別指向兩個不同的數字，找尋哪兩個數字總和為 target

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =nums.size();
        for(int i=0;i<n-1;++i){
            for(int j = i+1;j<n;++j){
                int sum = nums[i] + nums[j];
                if(target == sum) return {i,j};
            }
        }
        return {-1,-1};
    }
};
```
#### sorting
- 先排序，在用雙指標從排序後的陣列找出兩個元素其總和為target，再回原本陣列找出其索引。

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr = nums;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int l =0, r = n-1;
        while(l<r){
            int sum =arr[l] + arr[r] ;
            if(sum==target) break;
            else if(sum<target) l++;
            else r--;
        }
        int ret1 = arr[l], ret2 = arr[r];
        vector<int> ret(2,-1);
        for(int i=0;i<nums.size();++i){
            if(nums[i]==ret1 && ret[0]==-1) ret[0] = i;
            else if(nums[i] ==ret2) ret[1] = i;
        }
        return ret;
    }
};
```

#### hash table
- 利用hash table 紀錄出現過元素及其索引

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n= nums.size();
        for(int i=0;i<n;++i){
            if(mp.count(target - nums[i])) return {mp[target-nums[i]], i};
            mp[nums[i]] = i;                  
        }
        return {-1,-1};
    }
};
```

## analysis
- brute force
    - time complexity `O(n^2)`
    - space complexity `O(1)`
- sorting
    - time complexity `O(nlogn)`
    - space complexity `O(n)`
- hash table 
    - time complexity `O(n)`
    - space complexity `O(n)`