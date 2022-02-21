---
title: GenomicRangeQuery
categories: 
    - codility
    - Prefix Sum
comments: false
---
## [problem](https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/)


## solution 

```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<unordered_map>
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<char, int> dna = { 
        {'A',1},
        {'C',2},
        {'G',3},
        {'T',4},
    };
    //      C   A   G   C   C   T   A
    //A     1   1   6   6   6   6   6
    //C     0   3   3   3   4   +   +
    //G     2   2   2   +   +   +   +
    //T     5   5   5   5   5   5   +
    int n = S.size();
    vector<int>A(n, n+1),C(n,n+1), G(n,n+1), T(n,n+1);
    int a = n-1, c = n-1, g= n-1, t = n-1;
    for(int i=n-1;i>-1;--i){
        if(S[i] == 'A'){
            A[i] = i;
            if(i+1<n) C[i] = C[i+1];
            if(i+1<n) G[i] = G[i+1];
            if(i+1<n) T[i] = T[i+1];
        }
        else if(S[i]=='C'){
            C[i] = i;
            if(i+1<n) A[i] = A[i+1];
            if(i+1<n) G[i] = G[i+1];
            if(i+1<n) T[i] = T[i+1];
        }
        else if(S[i] == 'G'){
            G[i] = i;
            if(i+1<n) A[i] = A[i+1];
            if(i+1<n) C[i] = C[i+1];
            if(i+1<n) T[i] = T[i+1];
        }
        else if(S[i] == 'T'){
            T[i] = i;
            if(i+1<n) A[i] = A[i+1];
            if(i+1<n) C[i] = C[i+1];
            if(i+1<n) G[i] = G[i+1];
        }
    }
    
    // for(int a:A) cout<<a<<" ";
    // cout<<endl;
    // for(int a:C) cout<<a<<" ";
    // cout<<endl;
    // for(int a:G) cout<<a<<" ";
    // cout<<endl;
    // for(int a:T) cout<<a<<" ";
    // cout<<endl;
    vector<int> ret;
    n = P.size();
    for(int i=0;i<n;++i){
        int s = P[i], e = Q[i];
        int mn = 5;
        // cout<<s<<" "<<e<<endl;
        if(A[s] >= s && A[s]<=e) mn = min(mn, dna['A']);
        if(C[s] >= s && C[s]<=e) mn = min(mn, dna['C']);
        if(G[s] >= s && G[s]<=e) mn = min(mn, dna['G']);
        if(T[s] >= s && T[s]<=e) mn = min(mn, dna['T']);
        ret.push_back(mn);
    }

    return ret;
}

```

## analysis
- time complexity `O(n+m)` m is the number of query
- space complexity `O(n)`