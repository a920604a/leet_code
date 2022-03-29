---
title: 79. Word Search

tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/word-search/)




## Solution
終止條件 `if(word.size() == k) return true;`

```c++
class Solution {
public:
    bool backtracking(vector<vector<char>>& board, string word, int i, int j,int k,  vector<vector<bool>> & visited){
        if(word.size() == k) return true;
        int n = board.size() , m= board[0].size();
        if(i<0 || j< 0 || i>n-1 || j>m-1 || visited[i][j]) return false;
        
        if(board[i][j] !=word[k]) return false;
        visited[i][j] = true;
        bool ret =  backtracking(board, word, i+1,j, k+1, visited) || \
            backtracking(board, word, i,j+1, k+1, visited) || \
            backtracking(board, word, i-1,j, k+1, visited) || \
            backtracking(board, word, i,j-1, k+1, visited) ;
        
        visited[i][j] = false;
        return ret;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m= board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m, false));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){   
                if(board[i][j] == word[0] &&  backtracking(board, word, i, j, 0, visited)) return true;
            }
        }
        
        return false;
    }
};
```


- 也可以不用visited 額外空間，只需要拜訪到的對board進行修改，結束後再恢復之前的狀態。

## analysis
- time complexity `O(4*n^2)`
- space complexity `O(n^2)`