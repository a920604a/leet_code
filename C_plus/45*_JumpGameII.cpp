class Solution
{
private:
    vector<int> memo;

public:
    int dp(vector<int> &nums, int p)
    {
        // 定义：从索引 p 跳到最后一格，至少需要 dp(nums, p) 步
        int n = nums.size();
        //base case
        if (p >= n - 1)
            return 0;

        if (memo[p] != n)
            return memo[p];

        int steps = nums[p];
        // 可以選擇跳 1步 2步 ...
        for (int i = 1; i <= steps; ++i)
        {
            int subProblem = dp(nums, p + i);
            memo[p] = min(memo[p], subProblem + 1);
        }
        return memo[p];
    }
    int jump(vector<int> &nums)
    {
        // option 1 brute force + memo

        // memo initalize
        //  2   3   1   1   4
        //  5   5   5   5   5
        //

        // int n = nums.size();
        // memo = vector<int>(n, n);
        // return dp(nums, 0);

        // option 2 dp
        // 最短步伐可以抵達index-i點
        //      2   3   1   1   4
        //      0   5   5   5   5
        //      0   1   1   5   5    i = 0 dp[j] = min(dp[j], dp[i]+1)
        //      0   1   1   2   2    i = 1
        //      0   1   1   2   2    i = 2, i = 3, i = 4

        //      1   2   1   1   1
        //      0   1   5   5   5     i = 0
        //      0   1   2   2   5      i = 1
        //      0   1   2   2   5      i = 2
        //      0   1   2   2   3       i = 3

        // int n = nums.size();
        // vector<int> dp(n, n);
        // dp[0] = 0; // base case
        // for(int i=0;i<n-1;++i){
        //     for(int j= i;j<n && j<=i + nums[i] ;++j) dp[j] = min(dp[j], dp[i]+1);
        // }
        // return dp[n-1];

        // option 2 貪心策略
        //  O(n) time O(1) space
        // 每一步都選最大步伐，例如i = 0 nums[i] = 2 就往前跳2步 index 2
        //                     i = 1 nums[i] = 3 就往前跳3步到index 4
        //  2   3   1   1   4
        //  i=0, farthest = 2 , end = 2, jumps = 1,
        //  i=1, farthest = 4 , end = 2, jumps = 1
        //  i=2, farthest = 4 , end = 4, jumps = 2
        //  i=3, farthest = 4 , end = 4, jumps = 2
        // i 和end 標記了可以選擇的跳躍步數
        // farthest標記了所有選擇[i...end]可以跳到的最遠距離

        int n = nums.size();
        int end = 0, farthest = 0;
        int jumps = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            farthest = max(nums[i] + i, farthest);
            if (end == i)
            {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};