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
            if(ret.back()[1] >= cur[1]){
                continue;
            }
            else if(ret.back()[1]>= cur[0] && ret.back()[1] <= cur[1]){
                ret.back()[1] = cur[1];
            }
            else if( ret.back()[1] < cur[0]){
                ret.push_back(cur);
            }
        }
        return ret;
    }
};