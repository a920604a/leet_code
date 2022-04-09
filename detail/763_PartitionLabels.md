---
title: 763. Partition Labels
tags:  
    - Interval
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/partition-labels/)


## solution

#### option 1 
```c++
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n= s.size();
        // 統計各字元出現的索引區間
        unordered_map<char,pair<int,int>> mp;
        vector<vector<int>> intervals;
        for(int i = 0;i<n ;++i){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = {i,i};
            }
            else{
                mp[s[i]].second = i;
            }
        }
        for(auto m:mp){
            intervals.push_back({m.second.first,m.second.second});
        }
        // 再將個區間看是否有無重疊，若可重疊使其重疊變成一個大區間，並尋找非重疊的大區間的長度
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0]<b[0];
        });
        vector<vector<int>> ret;
        ret.push_back({intervals[0][0], intervals[0][1]});
        for(int i=1;i<intervals.size() ;++i){
            vector<int> & cur = intervals[i];
            // non-overlap
            if(cur[0] > ret.back()[1]){
                ans.push_back(ret.back()[1] - ret.back()[0]+1);
                ret.push_back(cur);
            }
            // overlap
            else{
                ret.back()[1] = max(ret.back()[1], cur[1]);
            }
        }
        ans.push_back(ret.back()[1] - ret.back()[0]+1);
        return ans;
            
        
    }
};
```

#### option 2 - opt option 1
```c++
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ret;
        int n = s.size(), start = 0, last = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < n; ++i) m[s[i]] = i;
        for(int i=0;i<n;++i){
            last = max(last, m[s[i]]);
            if (i == last) {
                ret.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`