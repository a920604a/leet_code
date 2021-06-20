class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        string ret;
        int keep = num.size() - k;
        for (int i = 0; i < num.size(); ++i)
        {

            while (!ret.empty() && ret.back() > num[i] && k)
            {
                ret.pop_back();
                k--;
            }
            ret += num[i]; //push_back
        }

        ret.resize(keep); // ret.erase(keep, string::npos);
        int s = 0;
        while (ret[s] == '0' && s < ret.size())
            s++;
        ret.erase(0, s);

        return ret == "" ? "0" : ret;
    }
};