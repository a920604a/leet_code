---
title: StoneWall
categories: 
    - codility
    - Stacks and Queues
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/)

## solution
```c++
/// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<stack>
int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    
    // monotonic stack
    stack<int> sta;
    int n = H.size(), block = 0;
    //  8   8   5   7   9   8   7   4   8
    //
    for(int i=0;i<n;++i){
        while(!sta.empty() && sta.top() > H[i] ){
            
            sta.pop();
        }
        if(sta.empty() || sta.top() < H[i] ) {
            sta.push(H[i]);
            block++;
        }
    }
    return block ;
}
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`


