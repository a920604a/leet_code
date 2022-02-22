---
title: 36. Valid Sudoku
tags:  
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/valid-sudoku/)

## solution
```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m= board[0].size();
        // check each row
        for(int i=0;i<n;++i){
            unordered_set<char> s;
            for(char c:board[i]){
                if(c=='.') continue;
                else if(s.find(c)!=s.end()) return false;
                s.insert(c);
            }
        }
        // check each column
        for(int j=0;j<m;++j){
            unordered_set<char> s;
            for(int i=0;i<n;++i){
                if(board[i][j]=='.') continue;
                else if(s.find(board[i][j]) !=s.end()) return false;
                s.insert(board[i][j]);
            }
        }
        
        // check each small square
        // [0,0],[0,1],[0,2],[1,0],[1,1],[1,2],[2,0],[2,1],[2,2]
        // [0,3],[0,4],[0,5],[1,3],[1,4],[1,5],[2,3],[2,4],[2,5]
        //...
        // [3,0],[3,1],[3,2],[4,0],[4,1],[4,2],[5,0],[5,1],[5,2]
        
        vector<vector<int>> acts = {
            {0,0},{0,1},{0,2},
            {1,0},{1,1},{1,2},
            {2,0},{2,1},{2,2}
        };
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                unordered_set<char> s;
                for(auto p:acts){
                    int x = i+p[0], y = j+p[1];
                    if(board[x][y] == '.') continue;
                    if(s.count(board[x][y])) return false;
                    s.insert(board[x][y]);
                }
            }
        }
        return true;
    }
};
```
## analysis
- time complexity `O(nm)`
- space complexity `O(1)`
