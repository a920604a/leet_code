---
title: 51. N-Queens
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/n-queens/)

## solution

```c++
class Solution {
public:
    vector<vector<string>> ret;
    bool isValid(vector<string>& board, int r, int c){
        
        // 檢查所在行列是否有其他皇后
        for(int i=0;i<board.size(); ++i)
        {
            if(board[i][c] == 'Q') return false;
            if(board[r][i] == 'Q') return false;
        }
        
        // 左上角
        for(int i=r-1,j=c-1;i>-1 && j>-1 ;i--,j-- ){
            if(board[i][j] == 'Q') return false;
        }
        // 右上角 
        for(int i=r-1, j = c+1;i>-1 && j<board.size() ; i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void backtracking(vector<string> & board, int r){
    
        // 終止條件
        if(r==board.size()){
            ret.push_back(board);
            return;
        }
        
        for(int i=0;i<board[0].size();++i){
            
            if(!isValid(board, r,i)) continue;
            board[r][i] = 'Q';
            // 因為每列只會有一個皇后，所以放置完後處理下一列
            backtracking(board, r+1);
            board[r][i] = '.';
            
        }
        
        
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n,'.'));
        backtracking(board, 0);
        return ret;
    }
};
```