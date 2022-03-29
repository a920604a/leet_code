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
        int n = 9, m=9;
        // check each row
        for(int i= 0;i<n;++i){
            unordered_set<char> s;
            for(int j = 0;j<m;++j){
                if(board[i][j] == '.') continue;
                if(s.find(board[i][j]) != s.end()) return false;
                s.insert(board[i][j]);
            }
        }
        // check each col
        for(int j = 0;j<m;++j){
            unordered_set<char> s;
            for(int i=0;i<n;++i){
                if(board[i][j] == '.') continue;
                if(s.find(board[i][j]) != s.end()) return false;
                s.insert(board[i][j]);
            }
        }
        
        // check each block
        vector<vector<int>> dirs = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
        for(int i=0;i<n;i+=3){
            for(int j=0;j<m;j+=3){
                unordered_set<char> s;
                for(vector<int> d:dirs){
                    int x = i+d[0], y = j+d[1];
                    if(board[x][y] == '.') continue;
                    if(s.find(board[x][y]) != s.end()) return false;
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
- space complexity `O(nm)`
