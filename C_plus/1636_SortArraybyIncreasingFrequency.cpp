class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {

        unordered_map<int, int> m;
        vector<vector<int> > vec;
        for (int n : nums)
            m[n]++;
        vector<int> ret;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            vec.push_back({it->first, it->second});
        }
        sort(vec.begin(), vec.end(), [](vector<int> &a, vector<int> &b)
             {
                 if (a[1] == b[1])
                     return a[0] > b[0];
                 else
                     return a[1] < b[1];
             });
        for (int i = 0; i < vec.size(); ++i)
        {
            for (int _ = 0; _ < vec[i][1]; ++_)
                ret.push_back(vec[i][0]);
        }
        return ret;
    }
};