# 152. Maximum Product Subarray

###### tags: `leetcode` `dp` `Blind Curated 75`


## [problem](https://leetcode.com/problems/maximum-product-subarray/)

給定一陣列，求出乘積最大連續子陣列，並返回其值


## Solution

#### option 1 dp
- 維護兩dp，一條紀錄至今最小，一條紀錄至今最大，因為最大值可能是最小值乘以負數。
```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        vector<int> mn(n,1), mx(n,1);
        mn[0] = nums[0], mx[0] = nums[0];
        //      2   3   -2  4
        //mn    2   3   -6  -24
        //mx    2   6   -2  4
        
        
        int ret = nums[0];
        for(int i=1;i<n;++i){
            mn[i] = min(nums[i], min(mn[i-1]*nums[i], mx[i-1]*nums[i]));
            mx[i] = max(nums[i], max(mn[i-1]*nums[i], mx[i-1]*nums[i]));
            ret = max(ret, mx[i]);
        }
        return ret;
    }
};
```


#### option 2 - reduce version 
```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int mn = nums[0],mx = nums[0];
        int ret = nums[0];
        for(int i=1;i<n;++i){
            int pre_mn = mn;
            mn = min(nums[i], min(mn*nums[i], mx*nums[i]));
            mx = max(nums[i], max(pre_mn*nums[i], mx*nums[i]));
            ret = max(ret, mx);
        }
        return ret;
    }
};
```
## analysis
- option 1
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 2 
    - time complexity `O(n)`
    - space complexity `O(1)`
