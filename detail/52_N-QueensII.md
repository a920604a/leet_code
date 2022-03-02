---
title: 52. N-Queens II

tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/n-queens-ii/)

## solution
```c++
class Solution {
public:
    int ret = 0;
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
    void backtracking(vector<string>& board, int r){
        if(r==board.size()){
            ret++;
            return;
        }
        
        for(int i=0;i<board.size() ; ++i){
            if(isValid(board, r, i) == false) continue;
            board[r][i] = 'Q';
            backtracking(board, r+1);
            board[r][i] = '.';
        }
        
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        backtracking(board, 0);
        return ret;
    }
};
```