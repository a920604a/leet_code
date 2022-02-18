# 34. Find First and Last Position of Element in Sorted Array

###### tags: `leetcode` `Binary Search`



## [problem](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)


## solution

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2,-1);
        // avoid empty array
        if(nums.empty()) return ret;
        int n = nums.size();
        int l = 0, r =n;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) r = mid;
            else if(nums[mid]>target ) r=mid;
            else l = mid+1;
        }
        if(l>n-1 || nums[l] != target ) return ret;
        ret[0] = l;
        r = l;
        while(r+1<n && nums[r] == nums[r+1]) r++;
        ret[1] =r;
        return ret;
    }
};
```

## analysis
- time complexity `O(logn)`
- space complexity `O(1)`
