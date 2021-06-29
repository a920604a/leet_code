class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        // option 1 O(nlogn) sorting

        // sort(nums.begin(), nums.end());
        // int n = nums.size()-1;
        // return nums[n]*nums[n-1]-nums[0]*nums[1];

        // option 2 O(n) time O(1) space
        int lm = 0, rm = 0;
        int lmin = 10001, rmin = 10001;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            lm = max(lm, nums[l]);
            rm = max(rm, nums[r]);
            if (nums[l] >= nums[r])
                r--;
            else
                l++;
        }

        l = 0;
        r = nums.size() - 1;
        while (l < r)
        {
            lmin = min(lmin, nums[l]);
            rmin = min(rmin, nums[r]);
            if (nums[l] <= nums[r])
                r--;
            else
                l++;
        }
        cout << lm << " " << rm << " " << lmin << " " << rmin << endl;
        return lm * rm - lmin * rmin;
    }
};