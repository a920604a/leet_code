class Solution
{
public:
    int minMoves(vector<int> &nums)
    {

        // 數學問題
        //  [1, 2, 3] => 6 + m * 2 = 4 * 3 = > m = 3
        // sum + m次移動* (n-1) 個 = 最終結果 = x 平衡後的數字 * n 個

        // sum + m * (n-1 ) = n * x
        // 6 + m* 2 = 3 * x
        // minNum + m = x 帶入原式子 = sum + m(n-1) = n (minNum + m) = nm + n*minNum;
        //  sum - minNum * n = m

        int mn = INT_MAX, ret = 0;
        for (int n : nums)
            mn = min(n, mn);
        for (int n : nums)
            ret += (n - mn);
        return ret;
    }
};