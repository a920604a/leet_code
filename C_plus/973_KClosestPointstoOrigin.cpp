class Solution
{
public:
    vector<vector<int> > kClosest(vector<vector<int> > &points, int k)
    {
        // option 1 priority_queue
        priority_queue<pair<int, int> > q;
        vector<vector<int> > ret;
        int dis = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            q.push(make_pair(dis, i));
            if (i >= k)
                q.pop();
        }
        while (!q.empty())
        {

            ret.push_back(points[q.top().second]);
            q.pop();
        }
        return ret;

        // option 2 vector
        // vector<pair<int,int>> res;
        // vector<vector<int>>ans;
        // int dis = 0;
        // for(int i=0;i<points.size();++i){
        //     dis = pow(points[i][0], 2) + pow(points[i][1],2);
        //     res.push_back(make_pair(dis, i));
        // }
        // sort(res.begin(), res.end());
        // for(int i=0;i<k;++i){
        //     pair<int, int> p=res[i];
        //     ans.push_back(points[p.second]);
        // }
        // return ans;
    }
};