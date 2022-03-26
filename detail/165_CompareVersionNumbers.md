---
title: 165. Compare Version Numbers
tags:  
    - Math
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/compare-version-numbers/)

## solution
```c++
class Solution {
public:
    vector<int> split(string version){
        vector<int> ver;
        int l=0, ret = 0;
        while(l<version.size()){
            if(version[l] =='.') {
                ver.push_back(ret);
                ret=0;
            }
            else{
                ret = 10*ret + (version[l]-'0');
            }
            l++;            
        }
        if(ret!=0)  ver.push_back(ret);
        return ver;
        
    }
    int compareVersion(string version1, string version2) {
        vector<int> ver1 = split(version1), ver2 = split(version2);
        int l = 0,r = 0, n = ver1.size(), m = ver2.size();
        
        //"01"
        // "1"
        while(l<n && r<m){
            if(ver1[l] == ver2[r]){
                l++;
                r++;
            }
            else if(ver1[l] > ver2[r]) return 1;
            else if(ver1[l] < ver2[r]) return -1;
        }
        while(l<n ){
            if(ver1[l] >0) return 1;
            l++;
        }
        while(r<m){
            if(ver2[r] >0) return -1;
            r++;
        }
        return 0;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`