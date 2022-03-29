---
title: 41. First Missing Positive

tags:  
    - heap
    - math
    - sorting
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)


## solution
#### option 1 - cheat
```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    
        sort(nums.begin(),nums.end());
        int cur = 1;
        for(int n:nums){
            if(n==cur) cur++;

        }
        return cur;
    }
};
```


#### option 2 - heap
```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int n:nums){
            if(n>0) pq.push(n);
        }
        
        int ret = 1;
        while(!pq.empty()){
            int t = pq.top();
            pq.pop();
            while(!pq.empty() && t==pq.top()) pq.pop();
            if(ret==t) ret++;
            else return ret;
        }
        return ret;
        
    }
};
```
#### option 3 - histogram or hash table
```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vec(n+1, false);
        for(int i=0;i<n;++i){
            if(nums[i] >= 0 && nums[i]<=n) vec[nums[i]] = true;
        }
        for(int i=1;i<n+1;i++){
            if(vec[i] == false) return i;
        }
        return n+1;
    }
};
```

#### option 4 - swap

不斷地交換，直到放到對的位置
```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;++i){
            while(nums[i]>=1 && nums[i]<=n && nums[i]!= nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]) ;
        }
        for(int i=0;i<n ;++i){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
```
## analysis
- option 1
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- option 2 
    - time complexity `O(n)`
    - space complexity `O(k)`
- option 3
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 4
    - time complexity `O(n)`
    - space complexity `O(1)`