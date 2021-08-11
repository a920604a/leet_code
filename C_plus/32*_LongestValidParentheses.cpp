class Solution
{
public:
    int longestValidParentheses(string s)
    {
        // option 1
        // 遇到左括號，將索引堆入stack，
        // 遇到右括號，
        //   如果stack 為空，則將下一個索引記錄到start，
        //   如果不為空則將stack.pop，如果此時為空，更新結果

        //         int ret = 0;
        //         stack<int> sta;
        //         int start = 0;
        //         for(int i=0;i<s.size() ; ++i){
        //             if(s[i] == '('){
        //                 sta.push(i);
        //             }
        //             else if( s[i] == ')'){
        //                 if(sta.empty()) start = i+1;
        //                 else{
        //                     sta.pop();
        //                     if(sta.empty()) ret = max( i - start +1 , ret);
        //                     else ret  = max(ret, i - sta.top());
        //                 }

        //             }
        //         }
        //         return ret;

        // option 2 dp
        // https://bangbingsyb.blogspot.com/2014/11/leetcode-longest-valid-parentheses.html
        //  求極值一般可用dp，當遇到右括號，找前一個字符的最長括號串dp[i]的前一個字符

        //          (   (   )
        //    0     0   0   0
        //(   0
        //(
        //)
        // dp[i] 表示 s[i-1] 結尾的最長有效括號，
        // int n  = s.size(), maxLen= 0;
        // vector<int> dp(n+1,0);
        // for(int i=1;i<=n ; ++i){
        //     int j = i - 2 -dp[i-1];
        //     if(s[i-1] == '(' || j<0 || s[j] == ')') dp[i]= 0 ;
        //     else{
        //         dp[i] = dp[i-1] + 2 + dp[j];
        //         maxLen = max(maxLen, dp[i]);
        //     }
        // }
        // return maxLen;

        // option 3
        // two pointer
        int n = s.size();
        int l = 0, r = 0;

        int res = 0;
        for (int i = 0; i < n; ++i)
        {

            if (s[i] == '(')
                l++;
            else
                r++;
            if (l == r)
                res = max(res, 2 * r);
            else if (r > l)
                l = r = 0;
        }
        l = r = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] == '(')
                l++;
            else
                r++;
            if (l == r)
                res = max(res, 2 * l);
            else if (l > r)
                l = r = 0;
        }
        return res;
    }
};