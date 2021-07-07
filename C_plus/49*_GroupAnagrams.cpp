class Solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs)
    {

        // option 1 O(n^2 logn) time
        vector<vector<string> > ret;
        map<string, int> m;

        for (string str : strs)
        {
            string cand = str;
            sort(cand.begin(), cand.end());
            if (!m.count(cand))
            {
                m[cand] = ret.size();
                ret.push_back({});
            }
            ret[m[cand]].push_back(str);
        }
        return ret;
    }
};