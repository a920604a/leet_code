// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<map>
#include <algorithm>
int solution(int N, vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    // 圖中最大總和路徑
    // M = 5
    // (2,1) (2,3) (1,4) (2,4)
    

    vector<vector<int>> points;

    vector<vector<int>> edges(N, vector<int>(N,0));
    for(int i=0;i<(int)A.size();++i){
        edges[A[i] -1][B[i]-1]++;
        edges[B[i]-1][A[i]-1 ]++;
    }

    vector<vector<int>> vec;
    for(int i=0;i<(int)edges.size() ; ++i){
        int connect = 0;
        for(int e:edges[i]) connect+=e;
        vec.push_back({i+1,connect});
    }
    // 邊緣點權重為1 開始，也連接的從連接少的開始給點知權重
    sort(vec.begin(), vec.end(), [](vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    });
    int w = N;
    // 分配頂點權重
    for(int i=0;i<N;++i){
        points.push_back({vec[i][0], w});
        w--;
    }
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    });
    
    int ret = 0;
    for(int i=0;i<(int)A.size();++i){
        int from = points[A[i]-1][1];
        int to = points[B[i]-1][1];
        ret += (from + to);
    }
    
    return ret;

}
