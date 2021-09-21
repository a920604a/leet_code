class Solution
{
public:
    void traverse(vector<int> &nums, vector<int> &path, set<vector<int> > &ret, vector<bool> &used)
    {

        if (nums.size() == path.size())
        {
            ret.insert(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i])
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            traverse(nums, path, ret, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &nums)
    {
        //option 1
        set<vector<int>> ret;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        traverse(nums, path, ret, used);
        return vector<vector<int>>(ret.begin(), ret.end());

        // option 2
        set<vector<int> > res;
        permute(nums, 0, res);
        return vector<vector<int> >(res.begin(), res.end());
    }

    void permute(vector<int> &nums, int start, set<vector<int> > &ret)
    {

        if (start >= nums.size())
            ret.insert(nums);

        for (int i = start; i < nums.size(); ++i)
        {
            // prune
            if (i != start && nums[i] == nums[start])
                continue;
            swap(nums[start], nums[i]);
            permute(nums, start + 1, ret);
            swap(nums[start], nums[i]);
        }
    }
};