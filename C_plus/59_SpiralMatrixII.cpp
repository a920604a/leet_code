class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        if (n == 1)
            return {{1}};
        vector<pair<int, int> > action = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int> > res(n, vector<int>(n, 0));
        set<pair<int, int> > s;
        int times = n * n;
        int i = 0, j = 0, a = 0;
        int v = 0;
        while (times)
        {
            if (i < 0 || j < 0 || i > n - 1 || j > n - 1)
            { // bomb! change direct
                i -= action[a].first;
                j -= action[a].second;
                a++;
                a = a % 4;
                i += action[a].first;
                j += action[a].second;
                // cout<<"change x-y"<<endl;
                // cout<<i<<" "<<j<<endl;
            }

            cout << i << " " << j << endl;
            if (s.find(make_pair(i, j)) != s.end())
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
                        break;
                }

                cout << i << " " << j << endl;
            }

            if (s.find(make_pair(i, j)) == s.end())
            { //not yet visit
                v++;
                res[i][j] = v;
                s.insert(make_pair(i, j));
                i += action[a].first;
                j += action[a].second;
            }

            times--;
        }
        return res;
    }
};