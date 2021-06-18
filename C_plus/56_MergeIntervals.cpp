class Solution
{
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > ret;
        ret.push_back(intervals[0]);
        int n = intervals.size();
        for (int i = 1; i < n; ++i)
        {
            vector<int> v = ret[ret.size() - 1];
            if (intervals[i][0] <= v[1])
            { //merge
                ret.pop_back();
                v[1] = max(v[1], intervals[i][1]);
                ret.push_back(v);
            }
            else
                ret.push_back(intervals[i]);
        }
        return ret;
    }
};