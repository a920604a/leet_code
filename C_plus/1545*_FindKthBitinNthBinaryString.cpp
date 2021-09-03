class Solution
{
public:
    string invert(string s)
    {
        string ret;
        for (int i = 0; i < s.size(); ++i)
        {
            ret += (s[i] == '0' ? '1' : '0');
        }
        return ret;
    }

    string rev(string s)
    {

        string ret = s;
        ret += "1";
        string r = invert(s);
        reverse(r.begin(), r.end());
        ret += r;
        return ret;
    }
    char findKthBit(int n, int k)
    {

        // build
        if (n == 1)
            return '0';
        string ret = "0";
        while (n)
        {
            n--;
            ret = rev(ret);
        }

        return ret[k - 1];
    }
};