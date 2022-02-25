---
title: 1869. Longer Contiguous Segments of Ones than Zeros
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/)

## solution
```c++
class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones = 0, zeros = 0;
        int count0 = 0, count1= 0;
        for(char c:s){
            if(c=='1'){
                count1++;
                
                zeros = max(zeros, count0);
                count0 = 0;

            }
            else{
                count0++;
                
                ones = max(ones, count1);
                count1 = 0;
            }
        }
        ones = max(ones, count1);
        zeros = max(zeros, count0);
        return ones>zeros?true:false;
        
    }
};

```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`
