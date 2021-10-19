class Solution
{
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals)
    {

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1]; //終點降序排序
                 return a[0] < b[0];     // 起點做升序排序
             });

        vector<vector<int> > ret;
        int n = intervals.size();
        ret.push_back(intervals[0]);
        for (int i = 1; i < n; ++i)
        {
            vector<int> cur = intervals[i];
            if (ret.back()[1] >= cur[1])
            {
                continue;
            }
            else if (ret.back()[1] >= cur[0] && ret.back()[1] <= cur[1])
            {
                ret.back()[1] = cur[1];
            }
            else if (ret.back()[1] < cur[0])
            {
                ret.push_back(cur);
            }
        }

        // option 2
        // for(int i=1;i<n ;++i){
        //     vector<int> cur = intervals[i];
        //     if(cur[0] <= ret.back()[1]){
        //         // overlap
        //         ret.back()[0] =  min(ret.back()[0], cur[0]);
        //         ret.back()[1] =  max(ret.back()[1], cur[1]);
        //     }
        //     else{
        //         ret.push_back({cur[0], cur[1]});
        //     }
        // }
        // option 2.1

        vector<vector<int> > ret;
        sort(intervals.begin(), intervals.end());

        ret.push_back({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < intervals.size(); ++i)
        {
            vector<int> cur = intervals[i];
            if (cur[0] <= ret.back()[1])
            {
                ret.back()[1] = max(cur[1], ret.back()[1]);
            }
            else
            {
                ret.push_back({cur[0], cur[1]});
            }
        }

        return ret;
        return ret;
    }
};