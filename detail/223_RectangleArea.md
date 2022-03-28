---
title: 223. Rectangle Area
tags:  
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/rectangle-area/)
## solution
```c++
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //  加等號 是因為To be clear, two rectangles that only touch at the corner or edges do not overlap.
        if(rec1[2] <= rec2[0] ) return false;
        if(rec1[0] >= rec2[2]) return false;
        if(rec1[1] >= rec2[3] ) return false;
        if(rec1[3] <= rec2[1]) return false;
        return true;
    }
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        // determin overlap
        // overlap
        vector<int> rec1 = {ax1, ay1, ax2, ay2};
        vector<int> rec2 = {bx1, by1, bx2, by2};
        if(isRectangleOverlap(rec1 , rec2)){
            // intersection
            int inter_x1 = max(ax1, bx1) ;
            int inter_x2 = min(ax2, bx2);
            int inter_y1 = max(ay1, by1);
            int inter_y2 =  min(ay2, by2) ;
            int intersection = (inter_y2-inter_y1) * (inter_x2-inter_x1);
            int uion = (ay2-ay1)*(ax2-ax1) + (by2-by1)*(bx2-bx1);
            return uion - intersection;
        }
        // not overlap
        else{
            return (ay2-ay1)*(ax2-ax1) + (by2-by1)*(bx2-bx1);
        }
        
    }
};  
```
## analysis
- time complexity `O(1)`
- space complexity `O(1)`