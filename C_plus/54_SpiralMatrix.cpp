class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        vector<pair<int, int> > action = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int> > s;
        vector<int> ret;
        int i = 0, j = 0, a = 0;
        int times = matrix[0].size() * matrix.size();
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
            if (j > matrix[0].size() - 1 || j < 0 || i > matrix.size() - 1 || i < 0)
            {
                i -= action[a].first;
                j -= action[a].second;
                a++;
                a = a % 4;
                i += action[a].first;
                j += action[a].second;
                cout << "a: " << a << endl;
            }
            cout << i << " " << j << endl;

            if (s.find(make_pair(i, j)) == s.end())
            { // not visited

                s.insert(make_pair(i, j));
                ret.push_back(matrix[i][j]); // add node
                cout << "add set: " << i << " " << j << endl;
                cout << "add node: " << matrix[i][j] << endl;
                i += action[a].first;
                j += action[a].second;
            }
        }
        for (int r : ret)
            cout << r << " ";
        return ret;
    }
};