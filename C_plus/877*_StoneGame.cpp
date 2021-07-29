class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        // option 1 math
        // 假設雙方都很聰明
        // 條件： 1. 總共有奇數個石頭 2. 堆數是偶數
        // 因為總共有奇數個石頭，所以一定會有勝負。
        // 先下手可以控制自己拿到的是偶數堆還是奇數堆，
        //  2   1   9   5   奇數堆 1、3和偶數堆2、4
        // 以上面的例子，最開始可以選擇第1堆或第四堆，如果想要偶數堆就拿第四堆，這樣對手不管怎麼拿都是奇數堆

        // return true;

        // option 2 dp
        int n = piles.size();
        // 初始化 dp
        // dp 狀態 : 開始的索引 i  結束的索引j 當前輪到的人
        vector<vector<tuple<int, int> > > dp(n, vector<tuple<int, int> >(n, tuple<int, int>(0, 0)));
        // 举例理解一下，假设 piles = [3, 9, 1, 2]，索引从 0 开始
        // dp[0][1].fir = 9 意味着：面对石头堆 [3, 9]，先手最终能够获得 9 分。
        // dp[1][3].sec = 2 意味着：面对石头堆 [9, 1, 2]，后手最终能够获得 2 分。

        // base case
        for (int i = 0; i < n; ++i)
        {
            get<0>(dp[i][i]) = piles[i];
            // dp[i][i].first = piles[i];
            get<1>(dp[i][i]) = 0;
            // dp[i][i].second = 0 ;
        }

        // 斜著遍歷數組
        for (int l = 2; l <= n; ++l)
        {
            for (int i = 0; i <= n - l; ++i)
            {
                int j = l + i - 1;
                // 先手選擇最走邊或是最右邊的分數
                int left = piles[i] + get<1>(dp[i + 1][j]);
                int right = piles[j] + get<1>(dp[i][j - 1]);

                if (left > right)
                {
                    get<0>(dp[i][j]) = left;
                    get<1>(dp[i][j]) = get<0>(dp[i + 1][j]);
                }
                else
                {
                    get<0>(dp[i][j]) = right;
                    get<1>(dp[i][j]) = get<0>(dp[i][j - 1]);
                }
            }
        }
        tuple<int, int> ret = dp[0][n - 1];
        // cout<<get<0>(ret)<<" "<<get<1>(ret)<<endl;
        return get<0>(ret) - get<1>(ret);
    }
};