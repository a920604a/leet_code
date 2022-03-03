---
title: 752. Open the Lock

tags: 
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/open-the-lock/)


## solution

```c++
class Solution {
public:
    void plusOne(string & str, int i){
        if(str[i] =='9') str[i] = '0';
        else str[i]++;
        
    }
    void minusOne(string & str, int i){
        if(str[i] =='0') str[i] = '9';
        else str[i]--;    
    }
    int openLock(vector<string>& deadends, string target) {
        // bfs 
        unordered_set<string> dead(deadends.begin(), deadends.end());
        // visited set record what has seen
        unordered_set<string> visited({"0000"});
        queue<string> q({"0000"});
        int turns = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                string p =q.front();
                q.pop();
                if(dead.find(p) !=dead.end()) continue;
                if(p==target) return turns;
                for(int j =0;j<4;++j){
                    string str = p;
                    plusOne(str, j);
                    if(visited.find(str) == visited.end()){
                        q.push(str);
                        visited.insert(str);
                    }
                    string str2 = p;
                    minusOne(str2, j);
                    if(visited.find(str2) == visited.end()){
                        q.push(str2);
                        visited.insert(str2);
                    }
                }
            }
            turns++;
        }
        return -1;
        
    }
};
```