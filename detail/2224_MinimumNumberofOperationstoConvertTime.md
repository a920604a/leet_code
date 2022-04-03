---
title: 2224. Minimum Number of Operations to Convert Time
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/)

## solution
```c++
class Solution {
public:
    int convertTime(string current, string correct) {
        int diff_hour = 0, diff_min = 0;
        for(int i=0;i<2;++i){
            diff_hour = diff_hour*10 + (correct[i]-'0') - (current[i] - '0');
        }
        int count = diff_hour;
        for(int i=3;i<correct.size() ; ++i){
            diff_min = diff_min*10 + (correct[i]-'0') - (current[i] - '0');
        }
        if(diff_min<0){
            // 借位
            count--;
            diff_hour--;
            diff_min+=60;
            
        }
        while(diff_min>=15){
            diff_min-=15;
            count++;
        }
        while(diff_min>=5){
            diff_min-=5;
            count++;
        }
        while(diff_min>=1){
            diff_min-=1;
            count++;
        }
        return count;
        
    }
};

```
## analysis
- time complexity `O(1)`
- space complexity `O(1)`