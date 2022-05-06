---
title: 581. Shortest Unsorted Continuous Subarray
tags:  
    - Two Pointers

categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)

## solution

#### option 0 - Insert sort
```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 找尋最短子陣列，將子陣列經過升序排序，可以使得整個陣列呈現升序排列。
        //      2   6   4   8   10  9   15
        // 插入排序法
        int ret = 0, n = nums.size(), start = n-1;
        for(int i=1;i<n;++i){
            if(nums[i]<nums[i-1]){
                int key = nums[i];
                int j = i - 1;
                while (j > -1 && nums[j] > key)
                {
                    nums[j + 1] = nums[j];
                    j--;
                }
                nums[j + 1] = key;
                j++;
                start = min(start,j);
                ret = i - start + 1;
            }
            
        }
        return ret;    
    }
        
    
};
```
#### option 1 - sorting
```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 找尋最短子陣列，將子陣列經過升序排序，可以使得整個陣列呈現升序排列。
        //  2   6   4   8   10  9   15
        //  2   4   6   8   9   10  15
        //      i               j
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        
        int n = nums.size();
        if(n==1) return 0;
        int i=n-1, j=0;
        for(int k =0;k<n;++k){
            if(nums[k] !=vec[k]){
                i=min(i, k);
                j=max(j,k);
            }
        }
        // cout<<i<<" "<<j<<endl;
        return max(j-i+1, 0);
    }
};
```
```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 找尋最短子陣列，將子陣列經過升序排序，可以使得整個陣列呈現升序排列。
        //  2   6   4   8   10  9   15
        //  2   4   6   8   9   10  15
        //      i               j
        vector<int> vec = nums;
        int n = nums.size(), i = 0, j = n - 1;
        sort(vec.begin(), vec.end());
        while(i<n && nums[i] == vec[i]) i++;
        while(j>i && nums[j] == vec[j]) j--;
        return j - i + 1;
    }
};
```

#### option 3 - improve option 1
參考別人的
```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 找尋最短子陣列，將子陣列經過升序排序，可以使得整個陣列呈現升序排列。
        //      2   6   4   8   10  9   15
        //mn    15  9   9   8   4   4   2
        //mx    2   6   6   8   10  10  15
        //end   -2  -2  2   2   2   5   5
        //start -1  4   4   4   1   1   1
        int n = nums.size(), start = -1, end = -2;
        int mn = nums[n - 1], mx = nums[0];
        for (int i = 1; i < n; ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[n - 1 - i]);
            if (mx > nums[i]) end = i;
            if (mn < nums[n - 1 - i]) start = n - 1 - i;
            // cout<<mn<<" "<<mx<<" "<<end<<" "<<start<<endl;
        }
        return end - start + 1;
    }
};
```
## analysis
- option 1
    - time complexity `O(n*n)`
    - space complexity `O(1)`
- option 2 
    - time complexity `O(nlogn)`
    - space complexity `O(n)`
- option 3
    - time complexity `O(n)`
    - space complexity `O(1)`