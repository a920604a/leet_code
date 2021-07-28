class Solution
{
public:
    int split(vector<int> &nums, int max)
    {
        // 定義： 在每個子數組和不超過 max 的條件下，計算nums 至少可以分割成多少的子數組
        //  單調遞減 函數
        // f(nums, 10) = 3
        //      7   2   5   10 , max = 10
        //      [7,2] [5] [10]  return 3
        // O(N)
        int count = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (sum + nums[i] > max)
            {
                // 當前 子數組和大於max 限制，則子數組不能再添加元素
                count++;
                sum = nums[i];
            }
            else
            {
                // 當前子數組和 還未到達 max 限制，繼續添加元素
                sum += nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int> &nums, int m)
    {

        // 最大子數組 取值範圍 必定是 閉區間 [maxs(nums), sum(nums)]
        int left = 0, right = 0;
        for (int n : nums)
        {
            left = max(left, n);
            right += n;
        }
        // option 1 窮舉法
        // for(int max= left; max<=right; ++max ){
        //     // 如果最大子數組是和是 max
        //     // 至少可以把nums 分成 n 個子數組
        //     int n= split(nums, max);
        //     if (n<=m) return max;
        // }

        // option 2  O(NlogS)
        // O(logS)
        right++; // 左閉右開所以right +1
        while (left < right)
        {
            // mid 代表 最大子數組和
            int mid = left + (right - left) / 2;
            int target = split(nums, mid);
            // 左側邊界 二元搜尋
            // 如果最大子數組是和是 mid， 至少可以把nums 分成target 個子數組

            if (target == m)
            {
                // 收縮右邊界，達到搜尋左邊界的目的
                right = mid;
            }
            else if (target < m)
            {
                // 最大子數組和 小於 m ，代表 最大子數組是和 mid上限高了，以致於 target < m，所以mid 減小一些
                right = mid;
            }
            else if (target > m)
            {
                left = mid + 1;
            }
        }

        return left;
    }
};