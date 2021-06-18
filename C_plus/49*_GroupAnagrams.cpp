class Solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs)
    {
        vector<vector<string> > ret;
        map<string, int> m;

        for (int i = 0; i < strs.size(); ++i)
        {

            string cand = strs[i];
            sort(cand.begin(), cand.end());

            if (!m.count(cand))
            {
                m[cand] = ret.size();
                ret.push_back({});
            }
            ret[m[cand]].push_back(strs[i]);
        }
        return ret;
    }
};