---
title: 318. Maximum Product of Word Lengths
tags:
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/maximum-product-of-word-lengths/)


## solution

#### option 1 - brute force, maybe TLE
- TLE
```c++
class Solution {
public:
    bool hasCommon(string a, string b){
        vector<int> nums(26,0);
        for(char c:a) nums[c-'a']++;
        for(char c:b){
            if(nums[c-'a']>0) return false;
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        int n = words.size(), ret = 0;
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size()>b.size();
        });
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                if(hasCommon(words[i], words[j])){
                    int size =  words[i].size()*words[j].size();
                    ret = max(ret,size);
                }
            }
        }
        return ret;
    }
};
```
- pre-process
```c++
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), ret = 0;
        // pre process
        vector<vector<int>> dict(n, vector<int>(26,0));
        for(int i=0;i<n;++i){
            for(char c:words[i]) dict[i][c-'a']++;
        }
        
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                bool isCommon = false;
                for(int c=0;c<26;++c){
                    if(dict[i][c]>0 && dict[j][c]>0){
                        isCommon = true;
                        break;
                    }
                }
                if(!isCommon){
                    int size = words[i].size()*words[j].size();
                    ret = max(size, ret);
                }
            }
        }
        return ret;
    }
};
```
#### option 2 - Bit Manipulation
```c++
class Solution {
public:
    int maxProduct(vector<string>& words) {
        // 因為只會是小寫字母 共 26 個，int共32 ，如此可以將每個word 編碼
        int ret= 0,  n= words.size();
        vector<int> mask(words.size(), 0);
        for(int i=0;i<n;++i){
            for(char c:words[i]) mask[i] |= 1<<(c-'a');
            // j<i 避免重複選擇
            for(int j = 0;j<i;++j){
                if(!(mask[i] & mask[j])) ret = max(ret, int(words[i].size()*words[j].size()));
            }
        }
        return ret;
    }
};
```

## analysis
- option 1
    - time complexity `O(n^2)`
    - space complexity `O(nm)`
- option 2
    - time complexity `O(n^2)`
    - space complexity `O(n)`