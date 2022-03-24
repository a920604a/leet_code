---
title: 402. Remove K Digits
tags:  
    - monotonic stack
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/remove-k-digits/)
 
給定一個以字串表示的非負數箒數num，移除這個數中的k位數字，使得剩下的數字最小。
## solution
因為越前面位數越大，所以要先被移除，維護一個monotonic stack(從stack頂部遞減)

```c++
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char> sta;
        int n = num.size();
        for(int i=0;i<n;++i){
            while(k && !sta.empty() && num[i]-'0' < sta.top()-'0'){
                sta.pop();
                k--;
            }
            sta.push(num[i]);
        }
        while(k){
            k--;
            sta.pop();
        }
        string ret;
        while(!sta.empty()){
            ret = sta.top()+ret;
            sta.pop();
        }
        int i=0;
        int m = ret.size();
        while(i<m && ret[i]=='0') i++;
        string ans = ret.substr(i, m-i+1);
        return ans==""?"0":ans;
        
    }
};
```
#### option 2 - string without stack
```c++
class Solution {
public:
    string removeKdigits(string num, int k) {
        // monotonic stack
        string ret;
        for(char cur:num){
            while(!ret.empty() && k && cur < ret.back() ){
                k--;
                ret.pop_back();
            }
            ret.push_back(cur);
        }
        while(k--) ret.pop_back();
        // remove zero leading
        while(!ret.empty() && ret[0] == '0') ret.erase(ret.begin());
        return ret.empty() ? "0" :ret;
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)` stack
