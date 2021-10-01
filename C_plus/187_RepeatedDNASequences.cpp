class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {

        // slide window
        string window;
        unordered_map<string, int> ret;
        int l = 0, r = 0;
        while (r < s.size())
        {
            char c = s[r++];
            window += c;
            if (r - l > 10)
            {
                char d = s[l++];
                window.erase(0, 1);
            }
            ret[window]++;
        }
        vector<string> ans;
        for (auto it = ret.begin(); it != ret.end(); ++it)
        {
            // cout<<it->first<<" "<<it->second<<endl;
            if (it->second > 1)
                ans.push_back(it->first);
        }

        return ans;
    }
};