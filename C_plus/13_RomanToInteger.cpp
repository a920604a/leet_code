class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> dict = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int ret = dict[s[0]];
        for (int i = 1; i < s.size(); ++i)
        {
            if (dict[s[i - 1]] < dict[s[i]])
                ret += (dict[s[i]] - 2 * dict[s[i - 1]]);
            else if (dict[i - 1] >= dict[i])
                ret += dict[s[i]];
        }

        return ret;
    }
};