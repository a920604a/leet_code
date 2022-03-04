---
title: 1588. Sum of All Odd Length Subarrays
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/)


## solution

#### option 1 - brute force
```c++
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        //  1   4   2   5   3
        int n = arr.size(), ret = 0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if((j-i+1)%2==1){
                    int sum = 0;
                    for(int k=i;k<=j;++k) sum+=arr[k];
                    ret+=sum;
                }
            }
        }
        return ret;
    }
};
```


#### option 2 - reduce
```c++
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        //  1   4   2   5   3
        int n = arr.size(), ret = 0;
        int total = 0;
        for(int a:arr) total+=a;
        int prev = 0, next = 0;
        for(int i=0;i<n;++i){
            int next = 0;
            for(int j=n-1;j>-1;j--){
                if((j-i+1)%2==1){
                    ret+=(total-prev-next);
                }
                next+=arr[j];
                
            }
            prev+=arr[i];
        }
        return ret;
    }
};
```
#### option 3 - prefix
```c++
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        //          1   4   2   5   3
        // prefix   1   5   7   12  15
        //  1
        // (5-1)
        // (7-5) + 7
        // (12-7)+(12-1) 
        // (15-12)+(15-5) + 15
        int n = arr.size(), ret = 0;
        for(int i=1;i<n;++i) arr[i]+=arr[i-1];
        for(int i=0;i<n;++i){
            for(int j =i-1;j>-1;j-=2){
                ret+=arr[i]-arr[j];
            }
            // odd
            if((i+1)%2==1) ret+=arr[i];
        }
        return ret;
    }
};
```
#### option 4 - *math
## analysis
- option 1
    - time complexity `O(n^3)`
    - space complexity `O(1)`
- option 2 
    - time complexity `O(n^2)`
    - space complexity `O(1)`
- option 3 - prefix
    - time complexity `O(n^2)`
    - space complexity `O(1)`
- option 4 - math
    - time complexity `O(n)`
    - space complexity `O(1)`