class Solution
{
public:
    void helper(string s, int k, string out, vector<string> &ret)
    {
        if (k == 0)
        {
            if (s.empty())
                ret.push_back(out);
        }
        else
        {
            for (int i = 1; i <= 3; ++i)
            {
                if (s.size() >= i && isValid(s.substr(0, i)))
                {
                    if (k == 1)
                        helper(s.substr(i), k - 1, out + s.substr(0, i), ret);
                    else
                        helper(s.substr(i), k - 1, out + s.substr(0, i) + ".", ret);
                }
            }
        }
    }
    bool isValid(string s)
    {
        if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0'))
            return false;
        int ret = atoi(s.c_str());
        return ret <= 255 && ret >= 0;
    }
    vector<string> restoreIpAddresses(string s)
    {

        vector<string> ret;
        helper(s, 4, "", ret);
        return ret;
    }
};