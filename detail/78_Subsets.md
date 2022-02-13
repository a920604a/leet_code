# 78. Subsets

###### tags: `leetcode` `backtracking`

## [problem](https://leetcode.com/problems/subsets/)
給定一個陣列，假設其元素都唯一，返回所有的子集。可以是任何順序

## solution
- 先new 一個`vector<vector<int>>`，然後用backtracking方式搜尋所有子集，直到長度超過陣列長度為止。
- 樹的每個節點的拜訪

```c++
class Solution {
public:
    void backtracking(vector<int>& nums, vector<int>&path, vector<vector<int>>& ret, int l){
        ret.push_back(path);
        int n = nums.size();
        for(int i=l ; i<n;i++){
            path.push_back(nums[i]);
            backtracking(nums, path, ret, i+1);
            path.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        backtracking(nums, path, ret, 0);
        return ret;      
    }
};
```
## analysis

time complexity `O(2^n)`
space complexity `O(n)`