/*
 * @Author: yuan
 * @Date: 2021-05-05 11:03:17
 * @LastEditTime: 2021-05-05 11:03:17
 * @FilePath: /C_plus/9732_KClosestPointstoOrigin.cpp
 */
class Solution
{
public:
    vector<vector<int> > kClosest(vector<vector<int> > &points, int k)
    {
        priority_queue<pair<float, int> > pq;
        vector<vector<int> > ret;
        for (int i = 0; i < points.size(); ++i)
        {
            // cout<<p[0]<<" "<<p[1]<<endl;
            float dis = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            pq.emplace(dis, i);
            if (i >= k)
                pq.pop();
        }
        // vector<int> tmp(k,0);
        while (!pq.empty())
        {
            pair<float, int> l = pq.top();
            pq.pop();
            ret.push_back(points[l.second]);
        }

        return ret;
    }
};