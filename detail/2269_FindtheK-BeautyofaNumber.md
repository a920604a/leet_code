---
title: 2269. Find the K-Beauty of a Number
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-the-k-beauty-of-a-number/)
## solution
```c++
class Solution {
public:
    bool isDivisor(string a, int num){
        // string to int
        int n = 0;
        for(char c:a) n= 10*n+(c-'0');
        // cout<<a<<"\t"<<n<<endl;
        if(n==0) return false;
        else return num%n==0;
        
    }
    int divisorSubstrings(int num, int k) {
        // sliding window to get all substring which size is k
        int count = 0 ;
        // int convert to string
        string strs;
        int x = num;
        while(x) {
            strs+=to_string(x%10);
            x/=10;
        }
        reverse(strs.begin(), strs.end());
        // cout<<strs<<endl;
        
        for(int i=k-1;i<strs.size();++i){
            string tmp = strs.substr(i-k+1, k);
            if(isDivisor(tmp, num)) count++;
        }
        return count;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`