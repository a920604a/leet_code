class Solution
{
public:
    string palindrome(string &s, int l, int r)
    {
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s)
    {

        // option 1 two point O(n^2) time and O(1) space
        //         int start = 0, len = 0;
        //         int n = s.size() ;
        //         for(int i=0;i<n ;){

        //             int l = i, r = i;
        //             while(r<n-1 && s[r] == s[r+1] ) r++;

        //             i = r+1;

        //             while(l>0 && r<n-1 && s[l-1] == s[r+1]){
        //                 l--;
        //                 r++;
        //             }

        //             if(r-l +1 > len){
        //                 start = l;
        //                 len = r-l +1;
        //             }
        //         }

        //         return s.substr(start , len);

        // option 2
        string ret;
        for (int i = 0; i < s.size(); ++i)
        {
            // 以 s[i] 为中心的最长回文子串
            string s1 = palindrome(s, i, i);
            // 以 s[i] 和 s[i+1] 为中心的最长回文子串
            string s2 = palindrome(s, i, i + 1);

            ret = ret.size() > s1.size() ? ret : s1;
            ret = ret.size() > s2.size() ? ret : s2;
        }
        return ret;
    }
};