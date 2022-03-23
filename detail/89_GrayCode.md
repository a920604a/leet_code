---
title: 89. Gray Code
tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/gray-code/)
## solution 
#### option 1 - Bit Manipulation

`i^(i>>1)` 與自己本身一半的值做xor

```c++
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(n<<1,0);
        for(int i=1;i<(n<<1);++i){
            ret[i] = i^(i>>1);
        }
        return ret;
        
    }
};
```
#### option 2
```c++
class Solution {
public:
    vector<int> grayCode(int n) {
        // if n= 1 ,  {0,1}
        // if n=2 , {00,01,11,10}
        // if n= 3, {000,001,011,010,110,111,101,100}
        // 以n=3當例子，前半段{000,001,011,010} 可以當作是n=2 {00,01,11,10} 在前面加上0，
        // 後半段{110,111,101,100} ，沒那麼直觀，是 reverse {00,01,11,10}(={10,11,01,00}) 再前面加上1
        
        vector<string> gray = {"0","1"};
        
        if(n==1) return {0,1};
        
        for(int i=2;i<=n;i++){
            int size = gray.size();
            vector<string> second = gray; 
            for(auto &r :gray){
                r = "0"+r;
            }
            
            reverse(second.begin(), second.end());
            for(auto &s:second){
                s = "1" +s;
            }
            gray.insert(gray.end(), second.begin(), second.end());
        }
        
        // consert string to int 
        vector<int> ret;
        for(string g:gray) ret.push_back(stoi(g,0,2)); // better than stoi(g);
        return ret;
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
