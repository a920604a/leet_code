class Solution
{
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target)
    {
        // O(n^3) time and O(1) space
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > ret;
        for (int i = 0; i < n - 3; ++i)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < n - 2; ++j)
            {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;

                int l = j + 1, r = n - 1;
                int sum = target - nums[i] - nums[j];
                // avoid overflow
                while (l < r)
                {
                    int eval = nums[l] + nums[r];
                    if (eval == sum)
                    {
                        ret.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1])
                            l++;
                        while (l < r && nums[r] == nums[r - 1])
                            r--;
                        l++;
                        r--;
                    }
                    else if (eval < sum)
                        l++;
                    else
                        r--;
                }
            }
        }
        return ret;
    }
};