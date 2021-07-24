class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //  option 1 滑動窗口 O(n+m)
        //         int left = 0, right = 0;
        //         unordered_map<char, int> window;
        //         int ans = 0;
        //         while(right <s.size()){
        //             char c = s[right];
        //             right++;

        //             window[c]++;
        //             // 進行左側裁剪
        //             while(window[c]>1){
        //                 char d = s[left];
        //                 left++;
        //                 window[d]--;

        //             }
        //             ans = max(ans, right - left);

        //         }
        //         return ans;

        // n^2 logn brute force
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            set<char> tmp;
            for (int j = i; j < s.size(); ++j)
            {
                if (tmp.find(s[j]) != tmp.end())
                    break;
                else
                    tmp.insert(s[j]);
            }
            res = max(res, int(tmp.size()));
        }
        return res;
    }
};