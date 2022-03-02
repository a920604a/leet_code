---
title: 40. Combination Sum II

tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/combination-sum-ii/)

找出所有組合總和為target 的子序列，每個元素只能取一次，每組組合必須唯一。
## sloution

`if(i>l && candidates[i-1]==candidates[i]) continue;` skip depulicate

```c++
class Solution {
public:
    void backtracking(vector<int>& candidates, int target, int l, vector<int>& path, vector<vector<int>>& ret){
        if(target<0) return;
        if(target == 0){
            ret.push_back(path);
            return;
        }
        for(int i=l;i<candidates.size() ; ++i){
            // avoid duplicate
            if(i>l && candidates[i-1]==candidates[i]) continue;
            if(target < candidates[i]) return;
            path.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i+1, path, ret);
            path.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> path;
        backtracking(candidates, target, 0, path, ret);
        return ret;
        
    }
};
```
## analysis
- time complexity `O(len(nums)^M)`, M if theight of our recursive
- space complexity `L` , L is the longest combination
