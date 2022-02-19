# 88. Merge Sorted Array

###### tags: `leetcode` `sorting`

## [problem](https://leetcode.com/problems/merge-sorted-array/)

## solution

#### option 1 - insert sort
```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // insert sort
        for(int i= m;i<nums1.size() ; ++i){
            int val = nums2[i-m];
            int j = i-1;
            while(j>-1 && nums1[j] > val){
                nums1[j+1] = nums1[j];
                j--;
            }
            nums1[j+1] = val;
        }
    }
};
```


#### option 2 - merge sort
```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // merge sort
        int l = 0, r = 0, i=0;
        vector<int> nums(m+n,0);
        while(l<m && r<n){
            if(nums1[l] < nums2[r]) nums[i] = nums1[l++];
            else nums[i] = nums2[r++];
            i++;
        }
        while(l<m) nums[i++] = nums1[l++];
        while(r<n) nums[i++] = nums2[r++];
        nums1 = nums;
    }
};
```
## analysis
- option 1 - insert sort 
    - time complexity `O(n^2)`
    - space complexity `O(1)`
- option 2 - merge sort
    - time complexity `O(n)`
    - space complexity `O(n)`