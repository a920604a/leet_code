# 217. Contains Duplicate


###### tags: `leetcode` `hash table` `Blind Curated 75`


## [problem](https://leetcode.com/problems/contains-duplicate/)
找出陣列中是否一重複的數字

## Solution

#### sorting
可以先sort 是否有前後兩元素相同

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=1;i<n;++i){
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
        
    }
};
```
#### hash table
set or map

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int n:nums){
            if(s.count(n)) return true;
            s.insert(n);
        }
        return false;

        // unordered_set<int> s;
        // for(int n:nums) s.insert(n);
        // return !( nums.size() == s.size());
        
    }
};
```
## analysis
- sorting
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- hash table
    - time complexity `O(n)` assuming set find operation cost const time
    - space complexity `O(n)`

