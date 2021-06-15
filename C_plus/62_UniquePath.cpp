/*
 * @Author: yuan
 * @Date: 2021-05-12 18:48:29
 * @LastEditTime: 2021-05-12 18:48:40
 * @FilePath: /leetcode/C_plus/62_UniquePath.cpp
 */
class Solution {
public:
    double level(int l, int r){
        double ret= 1;
        for(int i=l;i<=r;++i)  ret *=i;
        return ret;
        
    }
    double level(int n){
        if(n<=1) return 1;
        double ret = 1;
        for(int i=2;i<=n;++i) ret *=i;
        return ret;
    }
    int uniquePaths(int m, int n) {
        int max_ = max(n-1,m-1);
        double ret = level( max_+1 ,m+n-2 );
        int min_ = min(m-1,n-1);
        return ret/level(min_);
    }
};