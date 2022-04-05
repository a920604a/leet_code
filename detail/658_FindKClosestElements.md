---
title: 658. Find K Closest Elements
tags: 
    - heap
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-k-closest-elements/)
## solution
#### option 1 - Center expand
```c++
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = 0, cand = arr[0];
        for(int i = 1;i<n;++i){
            if(abs( arr[i] - x) < abs(cand - x)){
                idx = i;
                cand = arr[i];
            }
        }
        int l = idx ,  r=idx+1;
        
        vector<int> ret;
        while(k--){
            if(l>-1 && r<n && abs(arr[l] - x) <= abs(arr[r] - x)){
                ret.insert(ret.begin(), arr[l--]);
            }
            else  if(l>-1 && r<n && abs(arr[l] - x) > abs(arr[r] - x))   ret.push_back(arr[r++]);
            else{
                if(l>-1) ret.insert(ret.begin(), arr[l--]);
                else ret.push_back(arr[r++]);
            }
        }
        return ret;  
    }
};
```
- faster version
```c++
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = 0, cand = arr[0];
        for(int i = 1;i<n;++i){
            if(abs( arr[i] - x) < abs(cand - x)){
                idx = i;
                cand = arr[i];
            }
        }
        int l = idx ,  r=idx+1;
        
        vector<int> left,ret;
        while(k--){
            if(l>-1 && r<n && abs(arr[l] - x) <= abs(arr[r] - x)){
                left.push_back(arr[l--]);
            }
            else  if(l>-1 && r<n && abs(arr[l] - x) > abs(arr[r] - x))   ret.push_back(arr[r++]);
            else{
                if(l>-1) left.push_back(arr[l--]);
                else ret.push_back(arr[r++]);
            }
        }
        reverse(left.begin(), left.end());
        for(int t:ret) left.push_back(t);
        return left;  
    }
};
```
#### option 2 - heap
```c++
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ret;
        auto cmp = [](auto &a, auto &b){
            if(a.second == b.second) return a.first>b.first;
            return a.second>b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        int n = arr.size();
        for(int i=0;i<n;++i) pq.push({i, abs(arr[i]- x)});
        while(k--){
            auto p = pq.top(); pq.pop();
            ret.push_back(arr[p.first]);
        }
        sort(ret.begin(), ret.end());
        return ret;
        
    }
};
```
#### option 3 - Binary Search and Center expandCenter expand
```c++
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l =0,r = n-1;
        // binary search closest value in array
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid] == x) { r = mid; break;}
            
            if(arr[mid] < x) l = mid+1;
            else r = mid-1 ;
        }
        l = r , r = r+1;
        vector<int> left,ret;
        while(k--){
            if(l>-1 && r<n && abs(arr[l] - x) <= abs(arr[r] - x)) left.push_back(arr[l--]);
            else  if(l>-1 && r<n && abs(arr[l] - x) > abs(arr[r] - x))   ret.push_back(arr[r++]);
            else{
                if(l>-1) left.push_back(arr[l--]);
                else ret.push_back(arr[r++]);
            }
        }
        reverse(left.begin(), left.end());
        for(int t:ret) left.push_back(t);
        return left;  
    }
};
```

## analysis
- option 1
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 2
    - time complexity `O(nlog(k)) + O(nlog(n))`
    - space complexity `O(k)`
- option 3
    - time complexity `O(logn + k)`
    - space complexity `O(1)`
