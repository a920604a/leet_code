class Solution {
public:
    void backtrack(vector<string> & board, int row, int & ret){
    
         if(board.size() == row){
                ret++;
                return ;
            }
        
        int n= board.size();
        for(int i=0;i<n ; ++i){
            
            if(!isValid(board, row, i)) continue;
            
            board[row][i] = 'Q';
            backtrack(board, row+1, ret);
            board[row][i] = '.';            
        }
    }
    
    bool isValid(vector<string> & board,int row, int col){
        
        int n= board.size();
        for(int i=0;i<n;++i){
           if(board[row][i]=='Q')  return false;
            if(board[i][col]=='Q')  return false;
            
        }
        
        // 右上角
        for(int i= row-1, j=col+1 ;i>-1 && j<n ;--i, j++){
            if(board[i][j] == 'Q') return false;
            
        }
        //左上角
        for(int i=row-1, j=col-1;i>-1&& j>-1;i--, j--){
            if(board[i][j] == 'Q') return false;
        }
        return true;
        
    }
    int totalNQueens(int n) {
        int ret = 0;
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, ret);
        return ret;
    }
};