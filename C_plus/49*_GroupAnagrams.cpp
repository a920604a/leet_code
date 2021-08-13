class Solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs)
    {
        vector<vector<string> > ret;
        unordered_map<string, int> m;

        int n = strs.size();

        for (int i = 0; i < n; ++i)
        {
            string cand = strs[i];
            sort(cand.begin(), cand.end());
            if (m.count(cand))
            {
                int idx = m[cand];
                ret[idx].push_back(strs[i]);
            }
            else
            {
                m[cand] = ret.size();
                ret.push_back({});
                ret.back().push_back(strs[i]);
            }
        }
        return ret;
    }
};