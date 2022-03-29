---
title: 496. Next Greater Element I
tags:  
    - monotonic stack
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/next-greater-element-i/submissions/)


## solution

#### option 1 - brute force

```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         // option 1 brute force
        vector<int> ret;
        for(int n:nums1){
            int i=0, next = -1;
            while(nums2[i]!=n) i++;
            for(i =i+1 ;i<nums2.size();i++){
                if(nums2[i]>n){
                    next = nums2[i];
                    break;
                }
            }
            ret.push_back(next);
        }
        return ret;
    }
};
```


- hash table
```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        int n = nums1.size(), m= nums2.size();
        unordered_map<int,int> mp;
        for(int i=0;i<m;++i) mp[nums2[i]] = i;
        for(int i=0;i<n;++i){
            int start = mp[nums1[i]], temp=-1;
            for(int j=start+1;j<m;++j){
                if(nums2[j]>nums1[i]){
                    temp = nums2[j];
                    break;
                }
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
```
#### option 2 - monotonic stack

- 維護一個單調遞增stack(從stack.top()看起)
- 需要一個hash table 存取 `nums2` 各元素及對應索引

```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> monoSta;
        unordered_map<int,int> index;
        int n = nums2.size();
        vector<int> ret(n, 0);
        for(int i=n-1;i>-1;i--){
            index[nums2[i]] = i;
            while(!monoSta.empty() && monoSta.top() <= nums2[i]  ){
                monoSta.pop();
            }
            if(monoSta.empty()) ret[i] = -1;
            else ret[i] = monoSta.top();
            monoSta.push(nums2[i]);
        }
        vector<int>ans;
        for(int q:nums1){
            ans.push_back(ret[index[q]]);
        }
        return ans;
    }
};
```


- other version
```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> monoSta;
        unordered_map<int,int> index;
        int n = nums2.size();
        vector<int> ret(n, -1);
        for(int i=0;i<n;++i){
            index[nums2[i]] = i;
            while(!monoSta.empty() && nums2[monoSta.top()] < nums2[i]){
                ret[monoSta.top()] = nums2[i];
                monoSta.pop();
            }
            monoSta.push(i);
        }
        vector<int>ans;
        for(int q:nums1){
            ans.push_back(ret[index[q]]);
        }
        return ans;
    }
};
```
## anaysis
- option 1
  - time complexity `O(n^2)`
  - space complexity `O(1)`
- option 2 
  - time complexity `O(n)`
  - space complexity `O(n)`