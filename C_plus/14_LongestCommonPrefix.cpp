class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // O(n^2)
        string ret = "";
        int len = strs.size();
        for (int i = 0; i < strs[0].size(); ++i)
        {
            char cand = strs[0][i];
            int count = 1;
            for (int j = 1; j < len; ++j)
            {
                if (strs[j][i] == cand)
                    count++;
                else
                    break;
            }
            if (count == len)
                ret += cand;
            else
                break;
        }
        return ret;
    }
};