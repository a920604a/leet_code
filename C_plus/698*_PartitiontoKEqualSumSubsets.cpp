class Solution
{
public:
    vector<int> bucket;
    bool backtrack(vector<int> &nums, int index, int target)
    {

        //base case
        if (index == nums.size())
        {

            for (int i = 0; i < bucket.size(); ++i)
            {
                // 检查所有桶的数字之和是否都是 target
                if (bucket[i] != target)
                    return false;
            }
            // nums 成功平分成 k 个子集
            return true;
        }

        // 穷举 nums[index] 可能装入的桶
        for (int i = 0; i < bucket.size(); ++i)
        {
            // 剪枝，桶装装满了
            if (bucket[i] + nums[index] > target)
                continue;
            // 将 nums[index] 装入 bucket[i]
            bucket[i] += nums[index];
            // 递归穷举下一个数字的选择
            if (backtrack(nums, index + 1, target))
                return true;
            // 撤銷選擇
            bucket[i] -= nums[index];
        }
        // nums[index] 装入哪个桶都不行
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {

        if (k > nums.size())
            return false;
        int sum = 0;
        for (int n : nums)
            sum += n;

        if (sum % k != 0)
            return false;

        bucket = vector<int>(k);
        int target = sum / k;

        sort(nums.begin(), nums.end(), [](int a, int b)
             {
            return a>b; // 降序排列 });

        // option 1 O(k^n) time
        // return backtrack(nums, 0,target);

        // option 2 O(k*2^n) faster than option 1
        vector<bool> used(nums.size(), false);

        return backtrack(k, 0, nums, 0, used, target);
    }
    bool backtrack(int k, int bucket, vector<int> &nums, int start, vector<bool> &used, int target)
    {

        if (k == 0)
            return true;

        if (bucket == target)
            return backtrack(k - 1, 0, nums, 0, used, target);

        for (int i = start; i < nums.size(); ++i)
        {
            // 已經被裝入其他桶子
            if (used[i])
                continue;

            // 當前桶子 裝不下 nums[i]
            if (nums[i] + bucket > target)
                continue;

            used[i] = true;
            bucket += nums[i];

            cout << i << " " << bucket << " " << target << endl;
            if (backtrack(k, bucket, nums, i + 1, used, target))
                return true;

            used[i] = false;
            bucket -= nums[i];
        }
        return false;
    }
};