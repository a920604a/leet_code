class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &nums)
    {
        // O(n^2)
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3 || nums[0] > 0 || nums[nums.size() - 1] < 0)
            return ret;

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            int target = -nums[i];
            while (j < k)
            {
                if (target == nums[j] + nums[k])
                {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    k--;
                    j++;
                }
                else if (target > nums[j] + nums[k])
                    j++;
                else
                    k--;
            }
        }
        return ret;
    }
};