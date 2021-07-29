class Solution
{
private:
    // unordered_map<pair<int, int>, int> memo;
    map<pair<int, int>, int> memo;

public:
    int dp(int k, int n)
    {

        // 狀態、選擇
        // 當前狀態為 (K個雞蛋、Ｎ樓層)，返回這個狀態的最佳解

        //base case
        // 如果雞蛋數只有一顆，那只能限性掃描才不會打破超過一顆
        if (k == 1)
            return n;
        // 樓層為０，顯然不需要扔雞蛋
        if (n == 0)
            return 0;

        // 避免重複計算
        if (memo.count(make_pair(k, n)))
            return memo[make_pair(k, n)];

        int ret = INT_MAX;

        // option 1 memo pattern time out
        // O(K*N^2) time, O(KN) space
        // 窮舉所有可能
        //         for(int i=1;i<=n ;++i){

        //             ret = min(ret,  1 + max(
        //                             dp(k, n-i),
        //                             dp(k-1,i-1)
        //                             )
        //                      );
        //         }

        // option 2 用binary search代替 dp的線性搜尋
        // O(K*N* logN) time, O(KN) space
        int lo = 1, hi = n;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int broken = dp(k - 1, mid - 1); // 碎
            int not_broken = dp(k, n - mid); // 沒碎
            // ret = min(   max(碎, 沒碎) + 1)

            if (broken > not_broken)
            {
                hi = mid - 1;
                ret = min(ret, broken + 1);
            }
            else
            {
                lo = mid + 1;
                ret = min(ret, not_broken + 1);
            }
        }

        memo[make_pair(k, n)] = ret;
        return ret;
    }
    int superEggDrop(int k, int n)
    {

        // option 1 memo pattern time out = up-bottom

        // return dp(k, n);

        // option 2 用binary search代替 dp的線性搜尋
        // return dp(k, n);

        // option 3 math

        // m 最多不會超過N次 (線性掃描)
        vector<vector<int> > dp(k + 1, vector<int>(n + 1, 0));

        // base case
        // dp[0][...] = 0
        // dp[...][0] = 0
        //
        int m = 0;
        while (dp[k][m] < n)
        {
            m++;
            for (int j = 1; j <= k; j++)
            {
                dp[j][m] = dp[j][m - 1] + dp[j - 1][m - 1] + 1;
            }
        }
        return m;
    }
};