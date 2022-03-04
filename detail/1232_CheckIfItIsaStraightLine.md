---
title: 1232. Check If It Is a Straight Line
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/check-if-it-is-a-straight-line/)

## solution
```c++
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n==2) return true;
        // int m = abs((coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]) );
        // avoid division by zero
        int m_a = coordinates[1][1]-coordinates[0][1];
        int m_b = coordinates[1][0]-coordinates[0][0];
        for(int i=2;i<n;++i){
            int temp_a = coordinates[i][1]-coordinates[i-1][1];
            int temp_b = coordinates[i][0]-coordinates[i-1][0];
            
            // if(m_a/m_b == temp_a/temp_b) return false;
            if(m_a*temp_b != m_b*temp_a) return false;
        }
        return true;
    }
};   
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`