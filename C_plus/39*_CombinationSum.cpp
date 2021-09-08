class Solution
{
public:
    vector<vector<int> > ret;
    void traverse(vector<int> &cand, int target, int l, int r, vector<int> &path)
    {
        if (target < 0)
            return;

        if (target == 0)
        {
            ret.push_back(path);
            return;
        }

        for (int i = l; i <= r; ++i)
        {
            path.push_back(cand[i]);
            traverse(cand, target - cand[i], i, r, path);
            path.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        vector<int> path;
        traverse(candidates, target, 0, candidates.size() - 1, path);
        return ret;
    }
};