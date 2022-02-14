# 560. Subarray sum equals k

###### tags: `leetcode` `hash table`


## [problem](https://leetcode.com/problems/subarray-sum-equals-k/)

找出連續子陣列，其總和為k 的數量

## solution
- hash table 統計連續子陣列總和及相應數量
```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // unordered_map<int,int> mp;
        // int sum =0, ret = 0;
        // mp[0] = 1;
        // //  1   2   3
        // //  (0,1) -> (0,1) (1,1) -> (0,1) (1,1) (2,1) -> (0,1) (1,1) (2,1) (3,1)
        // for(int i=0;i<nums.size() ; ++i){
        //     sum+=nums[i];
        //     if(mp.count(sum-k) ) ret+=mp[sum-k];
        //     mp[sum]++;
        // }
        // return ret;
        
        int n = nums.size();
        vector<int> sum = vector<int>(n+1,0);
        //  1   1   1
        //  0   1   2   3
        for(int i=1;i<=n;++i) sum[i] = sum[i-1] + nums[i-1];
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ret = 0;
        // (0,1) -> (0,1) (1,1) -> (0,1) (1,1) (2,1)
        for(int i=1;i<=n;++i){
            int target = sum[i] - k;
            if(mp.count(target)) ret+=mp[target];
            mp[sum[i]]++;
        }
        return ret;
    }
};
```
## analyze
- time complexity `O(n)` 
- space complexity `O(n)`
