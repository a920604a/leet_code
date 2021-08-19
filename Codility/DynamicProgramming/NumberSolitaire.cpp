// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    // O(n) time and O(n) space
    //  1   -2  0   9   -1  -2

    //  1   -1
    //

    // dp[ i] = max(dp[i], dp[i-1] + A[i]);
    int n = A.size();
    if (n == 2)
        return A[0] + A[1];
    vector<int> dp(n, -1e+5);
    dp[0] = A[0];
    for (int i = 1; i < n; ++i)
    {
        // 當下站在哪個位置
        for (int j = 1; j <= 6 && j <= i; ++j)
        {
            // j=
            dp[i] = max(dp[i], dp[i - j] + A[i]);
        }
        cout << endl;
    }
    return dp[n - 1];
}
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    //  1   -2  0   9   -1  -2

    //  1   -1
    //

    // dp[ i] = max(dp[i], dp[i-1] + A[i]);
    int n = A.size();
    if (n == 2)
        return A[0] + A[1];
    vector<int> dp(n, -1e+5);
    dp[0] = A[0];
    for (int i = 1; i < n; ++i)
    {
        // 當下站在哪個位置
        for (int j = 1; j <= 6 && j <= i; ++j)
        {
            // j=
            dp[i] = max(dp[i], dp[i - j] + A[i]);
        }
    }
    return dp[n - 1];
}