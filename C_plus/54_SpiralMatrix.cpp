class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        vector<pair<int, int> > action = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> ret;
        set<pair<int, int> > s;
        int i = 0, j = 0;
        int width = matrix[0].size(), height = matrix.size();
        int n = width * height;
        int a = 0;
        while (n)
        {
            cout << i << " " << j << endl; // trace code

            if (s.find(make_pair(i, j)) != s.end())
            { // select all possible direct
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
            }
            if (i > height - 1 || i < 0 || j > width - 1 || j < 0)
            { // bomp! , change direct
                i -= action[a].first;
                j -= action[a].second;
                a++;
                a = a % 4;
                i += action[a].first;
                j += action[a].second;
            }
            if (s.find(make_pair(i, j)) == s.end())
            { // not yet visit, visiting
                ret.push_back(matrix[i][j]);
                s.insert(make_pair(i, j));
                i += action[a].first;
                j += action[a].second;
            }

            n--;
        }
        return ret;
    }
};