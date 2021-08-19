// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    // O(L) time
    // dp 
    // N = 4
    //  0   1   2   3   4
    //  1   1   2   3   5
         
    // N = 5
    //  0   1   2   3   4   5
    //  1   1   2   3   5   8
    int n = A.size();
    int mx = 0;
    for(int a:A) mx = max(a, mx);
    vector<int> dp(mx+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=mx ; ++i) {
        // avoid overflow
        dp[i] = (dp[i-1] + dp[i-2])% (1<<30);
    }
    vector<int> ret;
    for(int i=0;i<n;++i){
        ret.push_back( dp[A[i]]%(1<<B[i])  );

    }
    return ret;
}