class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        return GetMax(nums, 0, nums.size() - 1);
    }

    int GetMax(vector<int> &nums, int l, int r)
    {

        if (l >= r)
            return nums[l];
        int mid = (l + r) / 2;
        int lmax = GetMax(nums, l, mid - 1);
        int rmax = GetMax(nums, mid + 1, r);
        int mmax = nums[mid];
        int temp = nums[mid];
        for (int i = mid - 1; i >= l; i--)
        {

            temp += nums[i];
            mmax = max(mmax, temp);
        }

        temp = mmax;
        for (int i = mid + 1; i <= r; ++i)
        {

            temp += nums[i];
            mmax = max(mmax, temp);
        }
        return max(mmax, max(lmax, rmax));
    }
};