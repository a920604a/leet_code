---
title: 179. Largest Number
tags:  
    - Math
    - Greedy
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/largest-number/)
## solution
bucket sort
```c++
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // bucket sort
        vector<vector<string>> bucket(10);
        for(int n :nums){
            string s = to_string(n);
            int c = s[0] -'0';
            bucket[c].push_back(s);
        }
        for(int i = 0 ;i<=9;++i){
            sort(bucket[i].begin(), bucket[i].end(), [](string a, string b){
               return a+b > b+a; 
            });
        }
        
        string ret;
        for(int i=9;i>-1;--i){
            for(string v:bucket[i]) ret += v;
        }
        int l=0;
        while(l<ret.size() && ret[l]=='0') l++;
        string ans = ret.substr(l);
        return ans.empty()?"0":ans;
        
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`
