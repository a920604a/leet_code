class Solution
{
public:
    int countSubstrings(string s)
    {
        // option 1 brute force
        int n = s.size();
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = i, r = i;
            while (l > -1 && r < n && s[l] == s[r])
            {
                l--;
                r++;
                ret++;
            }
            // 子回文字串長度 為偶數
            l = i, r = i + 1;
            while (l > -1 && r < n && s[l] == s[r])
            {
                l--;
                r++;
                ret++;
            }
        }
        return ret;

        // option 2 dp
        class Solution
        {
        public:
            int countSubstrings(string s)
            {
                // dp
                //  a   a   a
                //a t   t   t
                //a f   t   t
                //a f   f   t

                //      a   b   c
                //a     t   f   f
                //b         t   f
                //c             t
                int n = s.size();
                vector<vector<bool> > dp(n, vector<bool>(n));
                int ret = 0;
                //base case
                for (int i = 0; i < n; ++i)
                    dp[i][i] = true;
                ret += n;

                for (int i = n - 2; i > -1; i--)
                {
                    for (int j = i + 1; j < n; ++j)
                    {
                        if (s[i] == s[j])
                            dp[i][j] = (j - i <= 2) || dp[i + 1][j - 1];

                        if (dp[i][j])
                            ++ret;
                    }
                }
                return ret;
            }
        };
    }
};