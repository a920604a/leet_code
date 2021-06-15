/*
 * @Author: yuan
 * @Date: 2021-05-12 20:44:34
 * @LastEditTime: 2021-05-12 20:44:35
 * @FilePath: /C_plus/73_SetMatrixZeroes.cpp
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m=matrix[0].size();
        vector<pair<int,int>> v;
        vector<vector<int>> ret(matrix.begin(), matrix.end());
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]==0) v.push_back(make_pair(i,j));
            }
        }
        for(auto a:v){
            for(int i=a.first, j=0;j<m;j++) ret[i][j] = 0;
            for(int j=a.second, i=0;i<n;i++) ret[i][j] = 0;
            
        }
        matrix.clear();
        matrix.resize(0);  
        matrix = ret;
        // vector<vector<int>>matrix = (v.begin(), v.end());
    }
};