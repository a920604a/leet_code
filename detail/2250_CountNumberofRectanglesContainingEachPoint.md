---
title: 2250. Count Number of Rectangles Containing Each Point
tags:
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/)
## solution 
```c++
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        // TLE, O(nm)
        vector<int> ret;
        for(auto p:points){
            int count = 0;
            for(auto r:rectangles){
                if(p[0]<=r[0] && p[1]<=r[1]) count++;
            }
            ret.push_back(count);
        }
        return ret;
    }
};
```
#### option 1
Sort the rectangles at each height and use binary search.
```c++
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int n(size(rectangles)), maxy(0);
        for (auto& r : rectangles)   maxy = max(maxy, r[1]);
        vector<int> ls[maxy + 1];
        // vector<vector<int>> ls(maxy+1);
        for (auto& r : rectangles)  ls[r[1]].push_back(r[0]);
        for(int y = 0; y <= maxy; ++y)  sort(ls[y].begin(), ls[y].end());
        vector<int> ret;
        for(auto p:points){
            int res = 0;
            for (int y=p[1]; y<=maxy; ++y) {
                auto cnt = ls[y].end() - lower_bound(ls[y].begin(), ls[y].end(), p[0]);
                res += cnt;
            }
            ret.push_back(res);

        }
        return ret;
    }
};
```
## analysis
- time complexity `O(nlogm)`
- space complexity `O(nm)`