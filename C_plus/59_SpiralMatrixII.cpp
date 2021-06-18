class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        if (n == 1)
            return {{1}};
        int p = 1;
        vector<vector<int> > res(n, vector<int>(n, 1));
        // for(auto re:res){
        //     for(int r:re) cout<<r<<" ";
        //     cout<<endl;
        // }

        vector<pair<int, int> > action = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int> > s;
        vector<int> ret;
        int i = 0, j = 0, a = 0;
        int times = n * n;
        int v = 0;
        for (int k = 0; k < times; ++k)
        {
            if (s.find(make_pair(i, j)) != s.end()) // visited
            {
                for (int jj = 0; jj < 4; ++jj)
                {
                    i -= action[a].first;
                    j -= action[a].second;
                    a++;
                    a = a % 4;
                    i += action[a].first;
                    j += action[a].second;
                    if (s.find(make_pair(i, j)) == s.end())
                        break; //  not visited
                }
            }
            if (j > res[0].size() - 1 || j < 0 || i > res.size() - 1 || i < 0)
            {
                i -= action[a].first;
                j -= action[a].second;
                a++;
                a = a % 4;
                i += action[a].first;
                j += action[a].second;
            }
            cout << i << " " << j << endl;

            if (s.find(make_pair(i, j)) == s.end())
            { // not visited

                s.insert(make_pair(i, j));
                // ret.push_back(res[i][j]); // add node

                v++;
                res[i][j] = v;
                i += action[a].first;
                j += action[a].second;
            }
        }
        for (auto re : res)
        {
            for (int r : re)
                cout << r << " ";
            cout << endl;
        }
        return res;
    }
};