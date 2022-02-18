# 278. First Bad Version

###### tags: `leetcode` `Binary Search`


## [problem](https://leetcode.com/problems/first-bad-version/)

## solution 
```c++
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l =1, r = n;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isBadVersion(mid))  r= mid-1;
            else if(!isBadVersion(mid)) l = mid+1;
        }
        return l;
        
    }
};
```
## analysis
- time complexity `O(logn)`
- space complexity `O(1)`