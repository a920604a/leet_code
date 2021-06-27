class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // option 1 O(nlogn)
        // binary search
        if (nums.empty())
            return {-1, -1};
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
                break;
            else if (target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        if (nums[mid] != target)
            return {-1, -1};
        vector<int> ret;
        while (mid - 1 > -1 && nums[mid] == nums[mid - 1])
            mid--;
        ret.emplace_back(mid);
        while (mid + 1 < nums.size() && nums[mid] == nums[mid + 1])
            mid++;
        ret.emplace_back(mid);
        return ret;
    }
};