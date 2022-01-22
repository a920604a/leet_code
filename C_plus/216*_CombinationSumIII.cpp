class Solution
{
public:
    void dfs(int k, int target, vector<vector<int> > &ret, vector<int> &path, int l)
    {

        if (target < 0)
            return;
        if (target == 0)
        {
            if (k == 0)
                ret.push_back(path);
            return;
        }

        for (int i = l; i <= 9; ++i)
        {
            path.push_back(i);
            dfs(k - 1, target - i, ret, path, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int> > combinationSum3(int k, int n)
    {
        vector<vector<int> > ret;
        vector<int> path;
        dfs(k, n, ret, path, 1);
        return ret;
    }
};