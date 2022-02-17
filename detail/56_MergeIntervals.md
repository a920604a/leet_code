# 56. Merge Intervals

###### tags: `leetcode` `Interval` `Blind Curated 75`



## [problem](https://leetcode.com/problems/merge-intervals/)

## solution

```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>& b){
            if(a[0] == b[0] ) return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<vector<int>> ret;
        int n = intervals.size();
        int start = intervals[0][0], end = intervals[0][1];
        ret.push_back({start, end});
        for(int i=1;i<n;++i){
            vector<int> & cur = intervals[i];
            // overlap
            if(end>=cur[0]){
                end = max(cur[1], end);
                ret.back()[1] = end;
            }
            else{
                ret.push_back(cur);
                // update start and end variable
                start = cur[0];
                end = cur[1];
            }
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`