---
title: 289. Game of Life
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/game-of-life/)
## solution
#### option 1 
```c++
class Solution {
public:
    vector<vector<int>> neighbor = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,1},
        {1,-1},{1,0},{1,1}
    };
    int LiveNei(vector<vector<int>>& board, int i, int j){
        int n = board.size(), m = board[0].size();
        int live = 0;
        for(auto nei:neighbor){
            int x = i+nei[0], y = j+nei[1];
            if(x>-1 && x<n && y>-1 && y<m){
                if(board[x][y] == 1) live++;
            }
        }
        return live;
    }
    bool isLive(vector<vector<int>>& board, int i, int j){
        int live = LiveNei(board,i,j);
        if(board[i][j] == 0){
            if(live==3) return true;
            else return false;
        }
        else{
            if(live<2 || live>3) return false;
            else return true;
        }
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        // 少於兩個鄰居活者，自己將來會死
        // 兩三個鄰居活著，自己將來還活著
        // 超過三個以上鄰居活者，自己將來會被餓死。
        // 自己原先死了，但有剛好有三位活著的鄰居，自己會下一階段復活
        vector<vector<int>> nums = board;
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(isLive(board,i,j)) nums[i][j] = 1;
                else nums[i][j] = 0;
            }
        }
        board = nums;
    }
};
```
#### option 2 - in-place
```c++
class Solution {
public:
    vector<vector<int>> neighbor = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,1},
        {1,-1},{1,0},{1,1}
    };
    int LiveNei(vector<vector<int>>& board, int i, int j){
        int n = board.size(), m = board[0].size();
        int live = 0;
        for(auto nei:neighbor){
            int x = i+nei[0], y = j+nei[1];
            if(x>-1 && x<n && y>-1 && y<m){
                // 1->0 => 3
                // 1->1 => 1    
                if(board[x][y] %2 == 1) live++;
            }
        }
        return live;
    }
    int nextState(vector<vector<int>>& board, int i, int j){
        // 0->0 => 0
        // 0->1 => 2
        // 1->0 => 3
        // 1->1 => 1
        int live = LiveNei(board,i,j);
        if(board[i][j] == 0){
            if(live==3) return 2;
            else return 0;
        }
        else{
            if(live<2 || live>3) return 3;
            else return 1;
        }
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        // 少於兩個鄰居活者，自己將來會死
        // 兩三個鄰居活著，自己將來還活著
        // 超過三個以上鄰居活者，自己將來會被餓死。
        // 自己原先死了，但有剛好有三位活著的鄰居，自己會下一階段復活
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                board[i][j] = nextState(board,i,j);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == 3) board[i][j] = 0;
            }
        }
        
    }
};
```
## ananlysis
- time complexity `O(nm)`
- space complexity `O(nm)` `O(1)`