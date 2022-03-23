---
title: 393 UTF-8 Validation
tags:
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/utf-8-validation/)
## solution
```c++
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for(int i=0;i<n;++i){
            // ASCII
            if(data[i] < 0b10000000) continue;
            // 第一位的1 指示標誌符，後面連續跟多少個1，代表後面會有多少byte 以 10開頭
            // cnt 代表要從當前數字往後檢查多少個數字
            int cnt = 0, val = data[i];
            for(int j=7;j>=0 ; j--){
                if((data[i]>>j)&1 == 1) cnt++;
                else break;
            }
            
            if(cnt ==1 || cnt > 4 || cnt>n -i)  return false;
            for(int j =i+1 ; j<i+cnt ; j++){
                if(data[j] > 0b10111111 || data[j] < 0b10000000) return false;
            }
            i+= cnt-1;
        }
        return true;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`