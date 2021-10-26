class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &nums)
    {
        // option 1 two pointer O(n^2) time and O(1) space
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int l = i + 1, r = n - 1;
            int target = -nums[i];
            while (l < r)
            {
                if (nums[l] + nums[r] == target)
                {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                }
                else if (nums[l] + nums[r] < target)
                    l++;
                else
                    r--;
            }
        }
        return ret;
    }
};