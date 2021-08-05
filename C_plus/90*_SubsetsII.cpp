class Solution
{
public:
    //     Input: nums = [1,2,2]
    // Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
    void traverse(vector<int> &nums, int start, vector<int> &path, vector<vector<int> > &ret)
    {

        ret.push_back(path);

        for (int i = start; i < nums.size(); ++i)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            traverse(nums, i + 1, path, ret);
            path.pop_back();
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        vector<int> path;
        traverse(nums, 0, path, ret);
        return ret;
    }
};