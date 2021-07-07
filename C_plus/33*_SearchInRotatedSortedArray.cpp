class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] < nums[r])
            { // 右半部遞增
                if (target <= nums[r] && target > nums[mid])
                {
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            else if (nums[r] <= nums[mid])
            { //左半部遞增

                if (target >= nums[l] && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};