class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<string> ret(numRows);
        int n = s.size();
        int period = numRows * 2 - 2;
        for (int i = 0; i < n; ++i)
        {
            int mod = i % period;
            if (mod < numRows)
            {
                ret[mod] += s[i];
            }
            else
            {
                ret[period - mod] += s[i];
            }
        }
        string str;
        for (string s : ret)
            str += s;
        return str;
    }
};