class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // binary search O(logn) time
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[r])
            {
                // 右邊是遞增數列
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
            {
                // 左邊是遞增數列，加等好是因為mid==l時
                if (target >= nums[l] && nums[mid] >= target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};