class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
        // 給定陣列如果是 降序，說明是全排列的最後一種情況，下一個排序則是初始排序
        //  1   2   7   4   3   1
        //  1   3   1   2   4   7 下一排列
        //  step 1. 從右往左看，數字逐漸變大，直到2時才變小，
        //  step 2. 然後在從右往前找第一個比 2 大的數字，是3
        //  step 3. 將 2 3 交換，
        //  step 4. 把3後面的數字反轉，讓其保持升序

        int n = nums.size();
        int k;
        //  step 1.
        // 找 最大索引 滿足 nums[k] < nums[k + 1]
        for (k = n - 2; k > -1; k--)
        {
            if (nums[k] < nums[k + 1])
                break;
        }
        // k 小於 0 代表 給定陣列如果是 降序，說明是全排列的最後一種情況，下一個排序則是初始排序
        if (k < 0)
            reverse(nums.begin(), nums.end());
        else
        {
            // step 2. 然後在從右往前找第一個比 2 大的數字，是3
            int l;
            for (l = n - 1; l > k; l--)
            {
                if (nums[l] > nums[k])
                    break;
            }
            cout << l;

            // step 3.
            swap(nums[k], nums[l]);
            // step 4.
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};