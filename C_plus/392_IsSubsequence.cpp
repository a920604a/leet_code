class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        // option 1 dp O(NM) time and O(NM) space
        //        a   h   b   g   d   c

        //a       1   1   1   1   1    1
        //b       1   1   2   2   2    2
        //c       1   1   2   2   2    3

        //         int  m = s.size(), n  = t.size();

        //         vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        //         for(int i=1;i<=m;++i){
        //             for(int j = 1;j<=n ;++j){

        //                 if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] +1;
        //                 else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        //             }
        //         }
        //         return dp[m][n]==s.size();

        // option 2 O(N) time , N 為 t的長度

        // int l = 0;
        // for(int i=0;i<t.size() ;++i){
        //     if(t[i] == s[l]){
        //         l++;
        //     }
        // }
        // return l==s.size();

        // option 3 O(MlogN) time 如果 N 相對 M 很多 ，此種寫法較有效率。M s 的長度

        // 對t 進行預處理
        int m = s.size(), n = t.size();
        vector<vector<int> > index(256);
        for (int i = 0; i < n; ++i)
        {
            char c = t[i];
            // if(index[c] == nullptr) index[c] = list<int>();
            index[c].push_back(i);
        }

        vector<int> temp;
        int j = 0; // 指向t字串索引
        // 借助index 查找 s[i]
        for (int i = 0; i < m; ++i)
        {
            char c = s[i];
            if (index[c] == temp)
                return false;
            int pos = left_bound(index[c], j);
            cout << j << " " << pos << endl;
            if (pos == index[c].size())
                return false;

            j = index[c][pos] + 1;
        }
        return true;
    }
    int left_bound(vector<int> &arr, int tar)
    {
        int lo = 0, hi = arr.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (tar > arr[mid])
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }
};