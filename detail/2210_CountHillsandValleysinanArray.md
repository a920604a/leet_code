---
title: 2210. Count Hills and Valleys in an Array
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/)
## solution

```c++
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=1;i<n-1;++i){
            if(nums[i] > nums[i-1] ){
                // hills
                while(i<n-1 && nums[i] == nums[i+1])i++;
                if(i<n-1 && nums[i]>nums[i+1]) count++;
            }
            else if(nums[i]<nums[i-1]){
                // valley
                while(i<n-1 && nums[i] == nums[i+1]) i++;
                if(i<n-1 && nums[i] < nums[i+1]) count++;
            }
        }
        return count;
    }
};
```
 ## analysis
- time complexity `O(n)`
- space complexity `O(1)`
