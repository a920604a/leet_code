class Solution
{
public:
    vector<vector<int>> twoSumTarget(vector<int>& nums, int start, int target) {

        int lo = start, hi = nums.size() - 1;
        vector<vector<int>> res;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if (sum < target) {
                while (lo < hi && nums[lo] == left) lo++;
            } else if (sum > target) {
                while (lo < hi && nums[hi] == right) hi--;
            } else {
                res.push_back({left, right});
                while (lo < hi && nums[lo] == left) lo++;
                while (lo < hi && nums[hi] == right) hi--;
                }
            }
            return res;
        }

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

        // option 1.0.1 數組雙指針
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int target = 0;
        vector<vector<int>> ret;
        for(int i=0;i<n ;++i){
            vector<vector<int>> tuples = twoSumTarget(nums, i+1, target - nums[i]);
            
            for(vector<int> & tuple : tuples){
                tuple.push_back(nums[i]);
                ret.push_back(tuple);
            }
            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }
        return ret;

        
    }
};