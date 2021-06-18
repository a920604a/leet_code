class Solution
{
public:
    string say(string str)
    {
        int count = 1;
        char c = str[0];
        int j = 1;
        string ret = "";
        for (j = 1; j < str.size(); ++j)
        {
            if (str[j] == c)
                count++;
            else if (str[j] != c)
            {
                ret += (to_string(count) + str[j - 1]);
                count = 1;
                c = str[j];
            }
        }

        ret += (to_string(count) + str[j - 1]);
        return ret;
    }
    string countAndSay(int n)
    {
        string ret = "1";
        for (int i = 2; i <= n; ++i)
        {

            ret = say(ret);
        }

        return ret;
    }
};