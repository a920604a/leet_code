---
title: 2249. Count Lattice Points Inside a Circle
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/count-lattice-points-inside-a-circle/)
## solution
```c++
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> s;
        for(vector<int> &circle: circles){
            int ox = circle[0], oy = circle[1], r = circle[2];
            int lx = ox - r;
            int rx = ox + r;
            int ly = oy - r;
            int ry = oy + r;
            for(int x = lx;x<=rx;++x){
                for(int y = ly;y<=ry ; ++y){
                    // check 
                    if(pow((x-ox),2) +pow( (y-oy),2)<=r*r){
                        s.insert({x,y});
                    }
                }
            }
        }
        return s.size();
    }
};
```

## analysis
- time complexity `O(nxy)`
- space complexity `O(1)`