class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        // binary search O(logn)
        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            cout << l << " " << r << endl;
            // int mid = l+(r-l)/2;
            int mid = (l + r) / 2;
            cout << mid << endl;
            if (target == nums[mid])
                return mid;
            else if (nums[mid] >= nums[l])
            { // 左半部遞增

                if (target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            { //  nums[l]<nums[mid] 右半部遞增

                if (target <= nums[r] && target > nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};