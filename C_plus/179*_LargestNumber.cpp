class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {

        // 9xx , 8xx
        // put bucket

        vector<vector<string> > bucket(10);
        for (int n : nums)
        {
            string s = to_string(n);
            int h = s[0] - '0';
            bucket[h].push_back(to_string(n));
        }
        // sort 
        //  9 > 9991
        for (int i = 0; i <= 9; ++i)
        {
            sort(bucket[i].begin(), bucket[i].end(), [](string a, string b)
                 { return a + b > b + a; });
        }
        string ret = "";
        for (int i = 9; i >= 0; i--)
        {
            if (bucket[i].empty())
                continue;
            if (bucket[i].size() == 0)
                continue;
            for (string str : bucket[i])
                ret += str;
        }
        int l = 0;
        while (l < ret.size() && ret[l] == '0')
            l++;

        string str = ret.substr(l);
        return str.empty() ? "0" : str;
    }
};