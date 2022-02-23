---
title: NumberOfDiscIntersections
categories: 
    - codility
    - Stacks and Queues
comments: false
---

## [problem](https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/)

## solution
經典stack 教材
```c++
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include<stack>
int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<char> sta;
    for(char c:S){
        if(c=='(' || c=='[' || c=='{') sta.push(c);
        else{
            if(sta.empty()) return false;
            else if(sta.top() == '(' && c==')') sta.pop();
            else if(sta.top() == '[' && c==']') sta.pop();
            else if(sta.top() == '{' && c=='}') sta.pop();
            else return false;
        }
    }
    return sta.empty();
}

```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`


