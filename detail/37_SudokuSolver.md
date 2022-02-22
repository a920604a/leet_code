---
title: 37. Sudoku Solver
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/sudoku-solver/)

## solution
```c++
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c, char ch ){
        
        for(int i=0;i<9;++i){
            if(board[r][i] == ch) return false;
            if(board[i][c] == ch) return false;
            if(board[(r/3)*3+i/3][(c/3)*3 +i%3] == ch ) return false;
        }
        return true;
    }
    bool traverse(vector<vector<char>> & board, int r, int c){
        
        if(c==9) return traverse(board, r+1,0);
        if(r==9) return true;
        
        
        
        if(board[r][c]!='.') return traverse(board, r, c+1);
        
        for(char ch='1'; ch<='9' ;++ch){
            if(!isValid(board, r, c, ch)) continue;
            board[r][c] = ch;
            if(traverse(board, r, c+1)) return true;
            board[r][c] ='.';
        }
        return false;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        if (traverse(board, 0, 0))
            return;
    }
};
```

## analysis
- time complexity `O(9^nm)`
- sparse complexity `O(nm)`