---
title: 229. Majority Element II
tags:  
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/majority-element-ii/)

## solution


#### option 1 - hash tables
```c++

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int n:nums) freq[n]++;
        for(auto m:freq){
            if(m.second > n/3) ret.push_back(m.first);
        }
        return ret;
    }
};

```

#### option 2  - vote

```c++
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // 多數投票算法 O(n) time and O(1) space
        // from hint: 任意一數組出現次數大於 n/3 的數最多有兩個
        int n = nums.size();
        if(n==1) return {nums[0]};
        int freq1 = 0, cand1 = 0, freq2 = 0, cand2 = 0;
        for(int i=0;i<n;++i){
            if(nums[i] == cand1) freq1++;
            else if(nums[i] == cand2) freq2++;
            else if(freq1==0){ cand1 = nums[i];freq1=1;}
            else if(freq2==0) {cand2 = nums[i];freq2=1;}
            else{ freq1--; freq2--; }
        }
        // check 
        freq1 = freq2 = 0;
        for(int n:nums){
            if(n == cand1) freq1++;
            else if(n== cand2) freq2++;
        }
        vector<int> ret;
        if(freq1>n/3) ret.push_back(cand1);
        if(freq2>n/3) ret.push_back(cand2);
        return ret;
    }
};
```

## analysis
- option 1 - hash table 
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 1 - vote
    - time complexity `O(n)`
    - space complexity `O(1)`