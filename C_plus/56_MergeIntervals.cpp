class Solution
{
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals)
    {

        int size = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > ret = {intervals[0]};
        for (auto c : intervals)
        {
            for (int i : c)
                cout << i << " ";
            // cout<<endl;
        }
        cout << endl;
        int a = 1;
        while (a < size)
        {
            vector<int> v = ret.back();
            cout << v[0] << " " << v[1] << endl;
            cout << a << endl;
            // overlap
            if (v[1] >= intervals[a][0] && v[0] <= intervals[a][1])
            {
                //merge
                v[1] = max(v[1], intervals[a][1]);
                v[0] = min(v[0], intervals[a][0]);
                a++;
                ret.pop_back();
                ret.push_back(v);
                cout << "add nodes: " << v[0] << " " << v[1] << endl;
            }
            else
            {
                ret.push_back({intervals[a][0], intervals[a][1]});

                cout << "add node: " << intervals[a][0] << " " << intervals[a][1] << endl;
                a++;
            }
        }
        return ret;
    }
};