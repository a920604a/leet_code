---
title: 149. Max Points on a Line
tags:
    - hash table
    - Math
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/max-points-on-a-line/)
## solution
#### option 1
```c++
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ret = 0, n = points.size();
        for(int i=0;i<n;++i){
            map<pair<int,int> ,int> m;
            int duplicate = 1;
            for(int j = i+1;j<n;++j){
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcd(dx, dy);
                m[{dx/d,dy/d}]++;
            }
            
            ret = max(ret, duplicate);
            for(auto it = m.begin() ; it!=m.end() ; ++it){
                ret = max(ret, it->second+duplicate);
            }
        }
        return ret;
        
        
    }
    int gcd(int a, int b){
        return (b==0)?a:gcd(b, a%b);
    }
};
```

#### option 2 - math

## analysis
- time complexity `O(nlogn)`