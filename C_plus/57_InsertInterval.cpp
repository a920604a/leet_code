class Solution
{
public:
    vector<vector<int> > insert(vector<vector<int> > &intervals, vector<int> &newInterval)
    {

        intervals.push_back(newInterval);
        //         sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int>& b){
        //             return a[1]>b[1];

        //         });
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > ret;
        ret.push_back(intervals[0]);
        // [1,3] [2,5] = [1,5]
        // [1,8] [2,5]
        // [1,5] [7,10]

        for (int i = 1; i < intervals.size(); ++i)
        {
            vector<int> cur = intervals[i];
            if (ret.back()[1] >= cur[0] && ret.back()[1] <= cur[1])
            {
                // case 1
                ret.back() = {ret.back()[0], cur[1]};
            }
            else if (ret.back()[1] >= cur[0] && ret.back()[1] > cur[1])
            {
                continue;
            }
            else
            {
                ret.push_back(cur);
            }
        }
        return ret;
    }
};