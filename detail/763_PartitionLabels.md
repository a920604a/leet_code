---
title: 763. Partition Labels
tags:  
    - Interval
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/partition-labels/)


## solution
```c++
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> mp;
        int n = s.size();
        for(int i=0;i<n;++i){
            if(!mp.count(s[i])) mp[s[i]] = vector<int>(2, i);
            mp[s[i]][0] = min(mp[s[i]][0] , i);
            mp[s[i]][1] = max(mp[s[i]][1] , i);
        }
        
        vector<vector<int>> intervals;
        for(auto m:mp){
            intervals.push_back({m.second[0], m.second[1]});
        }
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>&b){
            if(a[0] == b[0]) return a[1]>b[1];
           return a[0]<b[0];
        });
        
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> ret;
        ret.push_back({start, end});
        for(int i=1;i<intervals.size();++i){
            vector<int> & cur = intervals[i];
            if( end < cur[0]){
                end = cur[1];
                start = cur[0];
                ret.push_back({start, end});
            }
            // overlap
            else{
                end = max(end, cur[1]);
                ret.back()[1] = end;
            }
        }
        vector<int> ans;
        for(auto v:ret){
            ans.push_back(v[1] - v[0]+1);
        }
        
        return ans;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`