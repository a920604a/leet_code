# 986. Interval List Intersections

###### tags: `leetcode` `Two Pointers`



## [problem](https://leetcode.com/problems/interval-list-intersections/)

## solution
```c++
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ret;
        int n = firstList.size(), m = secondList.size();
        int l =0,r=0;
        while(l<n && r<m){
            vector<int> cur1 = firstList[l];
            vector<int> cur2 = secondList[r];
            // non-overlap
            if(cur1[0] > cur2[1] || cur2[0]>cur1[1] ){
                if(cur1[1]<cur2[0]) l++;
                else r++;
            }
            else{
                //overlap
                ret.push_back({max(cur1[0], cur2[0]), min(cur1[1], cur2[1])});
                if(cur1[1]<cur2[1]) l++;
                else r++;
            }
        }
        return ret;
    }
};
```

## analysis
