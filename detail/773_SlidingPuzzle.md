---
title: 773. Sliding Puzzle
tags: 
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/sliding-puzzle/)

## solution

```c++
class Solution {
public:
    string encode(vector<vector<int>> & board){
        string str;
        int n = board.size(), m=board[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                str+= to_string(board[i][j]);
            }
        }
        return str;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        // bfs 
        //  [[1,2,3],[4,0,5]]
        //  encode = "123405"
        
        string target = "123450";
        // 紀錄鄰居的index
        vector<vector<int>> nei{
            {1,3},{0,2,4},{1,5},
            {0,4},{1,3,5},{2,4}
        };
        string str = encode(board);
        queue<string> q({str});
        unordered_set<string> visited({str});
        int step = 0;
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                string p = q.front();
                q.pop();
                if(p==target) return step;
                // find index of zero
                int idx = 0;
                for(;p[idx]!='0';idx++);
                // 零可以跟他的鄰居做交換
                for(int j:nei[idx]){
                    // 備份一份 p
                    string temp = p;
                    swap(temp[idx], temp[j]);
                    if(visited.find(temp) == visited.end()){
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
                
            }
            step++;
        }
        
        return -1;
    }
};
```
