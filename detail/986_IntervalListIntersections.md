---
title: 986. Interval List Intersections
tags:  
    - Two Pointers
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/interval-list-intersections/)

## solution
```c++
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // 假設以排序了，所以逐一比較各區間，在適時向右移動
        vector<vector<int>> ret;
        int n = firstList.size(), m = secondList.size(), l=0,r=0;
        // 重疊一定要兩個串列都能索引
        while(l<n && r<m){
            // 兩區間比較，會有四種狀況
            //case 1 [0,3], [2,5] => [2,3]
            //case 2 [2,5], [0,3] => [2,3]
            //case 3 [0,3], [1,2] => [1,2]
            //case 4 [1,2], [0,3] => [1,2]
            //case 5 [0,2], [3,4] => X
            //case 6 [3,4], [0,2] => X
            // case1~4 合併區間都是 [max(start_i), min(end_i)]
            
            // 重疊案例太多，判斷不重疊
            // non-overlap 
            if(firstList[l][1] < secondList[r][0] || firstList[l][0] > secondList[r][1]){
                if(firstList[l][1] < secondList[r][0]) l++;
                else r++;
            }
            else{

                ret.push_back({max(firstList[l][0], secondList[r][0]), min(firstList[l][1]  ,secondList[r][1] ) });
                // 決定誰右往右移
                if(firstList[l][1] < secondList[r][1]) l++;
                else r++;
            }
            
        }
        return ret;
    }
};
```

- other version

```c++

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // 假設以排序了，所以逐一比較各區間，在適時向右移動
        vector<vector<int>> ret;
        int n = firstList.size(), m = secondList.size(), l=0,r=0;
        // 重疊一定要兩個串列都能索引
        while(l<n && r<m){
            int a1 = firstList[l][0], a2 = firstList[l][1];
            int b1 = secondList[r][0], b2 = secondList[r][1];
            // overlap
            if(b2>=a1 && a2>=b1){
                ret.push_back({max(a1,b1), min(a2,b2)});
            }
            if(a2<b2) l++;
            else r++;
        }
        return ret;
    }
};

```

## analysis
- time complexity `O(nlogn)`
- span complexity `O(1)`