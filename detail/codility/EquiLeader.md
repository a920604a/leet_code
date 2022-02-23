---
title: EquiLeader
categories: 
    - codility
    - Leader
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/8-leader/equi_leader/)

## solution

事先算好 dominator 與 其次數，再不斷地計算兩區間的dominator個數是否大於其區間大小


```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int dominator(vector<int> & nums, int l, int r){
    if(l==r) return nums[l];
    int n = nums.size();
    int cand = nums[l], count = 1;
    for(int i=l+1;i<=r;++i){
        if(cand == nums[i] ) count++;
        else{
            count--;
            if(count==0){
                count =1;
                cand = nums[i];
            }
        }
    }
    // check more than half
    count = 0;
    for(int i=l;i<=r ; ++i){
        if(nums[i] == cand) count++;
    }
    if(count<=(r-l+1)/2) return -1;
    return cand;
}
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // test case    answer
    // [4,3,4,4,4,2]    2
    // [0,0]    1
    // [4, 4, 2, 5, 3, 4, 4, 4]  3
    // [2, 1, 1, 3] 0
    // [2, 1, 1, 1, 3]  1
    // 事先算好 dominator 與 其次數，再不斷地計算兩區間的dominator個數是否大於其區間大小
    int n = A.size(), count = 0;
    int cand = dominator(A, 0, n-1);
    if(cand==-1) return 0;
    for(int a:A) count+=(cand ==a?1:0);
    // cout<<count<<" "<<cand<<endl;
    int l = 0, r = count;
    count = 0 ;
    for(int i=0;i<n-1;++i){
        if(A[i] == cand){
            l++;
            r--;
        } 
        // two intervals [0,i], [i+1, n-1]
        if( l>(i+1)/2 && r> (n-1-i-1+1)/2 )  {
            count++;
            // cout<<"0-"<<i<<", "<<i+1<<"-"<<n-1<<"\t";
            // cout<<l<<" "<<r<<endl;
        }
    }

    return count;
}
```



## analysis
- time complexity `O(n)`
- space complexity `O(1)`


