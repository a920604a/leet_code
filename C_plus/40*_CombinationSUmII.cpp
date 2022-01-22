class Solution
{
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        vector<vector<int> > ret;
        combinationSum2(candidates, target, comb, ret, 0);
        return ret;
    }
    void combinationSum2(vector<int> &candidates, int target, vector<int> &comb, vector<vector<int> > &ret, int begin)
    {
        if (!target)
        {
            ret.push_back(comb);
            return;
        }
        for (int i = begin; i < candidates.size() && target >= candidates[i]; i++)
        {
            // if(i> l && candidates[i] == candidates[i-1])  continue;
            if (i == begin || candidates[i] != candidates[i - 1])
            {
                comb.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], comb, ret, i + 1);
                comb.pop_back();
            }
        }
    }
};