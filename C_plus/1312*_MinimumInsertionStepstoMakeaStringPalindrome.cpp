class Solution
{
public:
    int minInsertions(string s)
    {

        /*
        if (s[i] == s[j]) {
            dp[i][j] = dp[i + 1][j - 1];
        }
        else if(s[i] != s[j]){
            // 把 s[j] 插到 s[i] 右邊，同時把 s[i] 插到 s[j] 右邊
            dp[i][j] = dp[i + 1][j - 1] + 2;
            
            做選擇，先將 s[i..j-1] 或者 s[i+1..j] 變成回文串
            dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
        假設已經算出 dp[i+1][j-1] ，即已經知道 s[i+1...j-1] 成為回文的最小插入次數，
        那麼也可以認為s[i+1..j-1]已經是回文字串，
        所以通過 dp[i+1][j-1]推導 dp[i][j] 的關鍵就是在s[i] s[j]兩字符

        如果 s[i] = s[j] 不需要插入，只要將指標前進到 i+1 j-1 即可
            如果s[i] != s[j] ，分成兩種狀況，s[j] 插到 s[i] 右邊 ，同時把s[i] 插到 s[j] 右邊，那建構出來一定是回文字串。
            if(s[i] != s[j] ) dp[i][j] = dp[i + 1][j - 1] + 2;
        但是這種情況只需插入一個字符即可，"xaaaaa" 或是 "aaaaax" 當 i=0, j=5，所以當s[i] != s[j]時，無腦插入兩次可以變為回文字串但未必是插入最少。
            最佳插入方案應該是，
            step1 s[i..j-1] 或是 s[i+1..j]變為回文字串，誰變成回文字串插入次數少就選誰，min(dp[i][j-1], dp[i+1][j] )+1; 。
            step2 根據 step1 假如將s[i+1..j] 變為回文，那麼一定可以在s[i+1..j]右邊插入一個字符s[i]，一定可以將s[i..j]變成回文，同理s[i..j-1] 在左邊插入s[j]必定可以將s[i..j]變成回文。
        dp[i][j] = 3，即 s[i..j] 經過 最小插入次數3 可以成為回文
        */
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        // initalize dp, base case i==j 代表 i..j 已是回文
        for (int i = 0; i < n; ++i)
            dp[i][i] = 0;

        for (int i = n - 1; i > -1; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {

                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
                else if (s[i] != s[j])
                {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        return dp[0][n - 1];
    }
};