---
title: 6. Zigzag Conversion
categories: leetcode
comments: false
---
## [problem](https://leetcode.com/problems/zigzag-conversion/)
## solution
```c++
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> nums(numRows);
        int period = 2*numRows-2;
        for(int i=0;i<s.size() ; ++i){
            int mod = i%period;
            if(mod < numRows) nums[mod]+=s[i];
            else nums[period-mod]+=s[i];
        }
        string ret;
        for(string str:nums) ret+=str;
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`

