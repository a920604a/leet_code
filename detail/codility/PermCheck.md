---
title: PermCheck
categories: 
    - codility
    - Counting Elements
comments: false
---


## [problem](https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/)


## solution 

#### option 1 - sorting
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int pre = A[0], n=A.size();
    if(pre!=1) return 0;
    for(int i=1;i<n;++i){
        if(pre+1!=A[i]) return 0;
        pre++;
    }
    return 1;
}


```


#### option 2 - hash table
```c++

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
# include<unordered_set>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_set<int> st(A.begin(), A.end());
    int ret = 1, n=A.size();
    while(ret<=n){
        if(st.find(ret)==st.end()) return 0;
        ret++;
    }
    return 1;
}

```


#### option 3 - swap

放到正確的位置

```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        while (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i]) {
            swap(A[i], A[A[i] - 1]);
        }
    }
    // for(int a:A) cout<<a<<" ";
    for (int i = 0; i < n; ++i) {
        if (A[i] != i + 1) return 0;
    }
    return 1;
}


```
## analysis
- option 1 
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- option 2 
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 3
    - time complexity `O(n)`
    - space complexity `O(1)`

