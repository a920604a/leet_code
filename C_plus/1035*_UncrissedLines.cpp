class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        // option 1 dp from hint 1 O(MN) time and O(MN) space
        int a = nums1.size(), b = nums2.size();
        vector<vector<int> > dp(a + 1, vector<int>(b + 1, 0));
        for (int i = 1; i <= a; ++i)
        {
            for (int j = 1; j <= b; ++j)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    // dp[i][j] = 1+ min(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[a][b];

        // option 2 1-D dp + max() O(MN) time and O(N) space
        // option 3 recursion
    }
};