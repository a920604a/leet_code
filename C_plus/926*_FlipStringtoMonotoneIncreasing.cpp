class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {

        // two dp
        // dp0[i] 代表 [0..i-1] 子字串 最少的將 1 轉成 0 的個數，進而形成單調字串
        // dp1[j] 代表 [j..n-1] 子字串 最少的將 0 轉成 1 的個數，進而形成單調字串
        // 最後 dp0[i] + dp1[j] 最小的時候 即為答案

        //       00011000
        //dp0    000012222
        //dp1    654333210

        int n = s.size();
        int ret = INT_MAX;
        vector<int> dp0(n + 1), dp1(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            dp0[i] += dp0[i - 1] + (s[i - 1] == '1' ? 1 : 0);
        }
        for (int j = n - 1; j > -1; --j)
        {
            dp1[j] += dp1[j + 1] + (s[j] == '1' ? 0 : 1);
        }

        for (int i = 0; i <= n; ++i)
            ret = min(ret, dp0[i] + dp1[i]);

        return ret;
    }
};