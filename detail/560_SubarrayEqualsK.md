# Subarray sum equals k

###### tags: `hash table`


## [question](https://leetcode.com/problems/subarray-sum-equals-k/)

找出連續子陣列，其總和為k 的數量

## solution
hash table 統計連續子陣列總和及相應數量
```c++
unordered_map<int,int> mp;
        int sum =0, ret = 0, n = nums.size();
        mp[0] = 1;
        //  1   2   3
        //  (0,1) -> (0,1) (1,1) -> (0,1) (1,1) (2,1) -> (0,1) (1,1) (2,1) (3,1)
        for(int i=0;i<n ; ++i){
            sum+=nums[i];
            if(mp.count(sum-k) ) ret+=mp[sum-k];
            mp[sum]++;
        }
        return ret;
```
## analyze
time complexity `O(n)` 
space complexity `O(n)`
