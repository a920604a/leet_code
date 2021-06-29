class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        if (nums.size() == 1)
            return to_string(nums[0]);
        // 桶排列
        // 9xxx , 8xxx , 7xxx , 6xxx ,5xxx ,... 0xxx
        vector<vector<string> > bucket(10);
        // put into bucket
        for (int n : nums)
        {
            string s = to_string(n);
            int h = s[0] - '0';
            bucket[h].push_back(to_string(n));
        }

        // Append non-zeros
        string ret = "";
        for (int i = 9; i > 0; i--)
        {
            if (bucket[i].size() == 0)
                continue;
            sort(bucket[i].begin(), bucket[i].end(), [&](string &s1, string &s2)
                 { return s1 + s2 > s2 + s1; });

            for (int j = 0; j < bucket[i].size(); j++)
                ret += bucket[i][j];
        }

        // Append 0's only if the result has prefix numbers
        if (ret.length() > 0)
        {
            for (int j = 0; j < bucket[0].size(); j++)
                ret += bucket[0][j];
        }
        else if (bucket[0].size() > 0)
        {
            ret = "0"; // else just output "0"
        }

        return ret;
    }
};