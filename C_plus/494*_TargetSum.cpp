class Solution
{
public:
    void backtrack(vector<int> &nums, int i, int target, int &ret)
    {
        //base case 結束條件
        if (i == nums.size())
        {
            if (target == 0)
                ret++;
            return;
        }

        // 選擇負號
        target += nums[i];                   //做選擇
        backtrack(nums, i + 1, target, ret); // 窮舉所有選擇
        target -= nums[i];                   // 撤銷選擇
        //backtrack(nums, i+1, target+nums[i], ret);

        // 選擇正號
        target -= nums[i];                   //做選擇
        backtrack(nums, i + 1, target, ret); // 窮舉所有選擇
        target += nums[i];                   // 撤銷選擇
        //backtrack(nums, i+1, target-nums[i], ret);
    }

    int dp(vector<int> &nums, int i, int target, unordered_map<string, int> &memo)
    {

        //base case 結束條件
        if (i == nums.size())
        {
            if (target == 0)
                return 1;
            return 0;
        }

        // 轉為字串
        string key = to_string(i) + "," + to_string(target);

        // 用memo避免重複計算
        if (memo.count(key))
            return memo[key];

        // 選擇正號與服好的排列組合，窮舉
        int result = dp(nums, i + 1, target - nums[i], memo) +
                     dp(nums, i + 1, target + nums[i], memo);
        memo[key] = result;
        return result;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        //         def backtrack(路径, 选择列表):
        //         if 满足结束条件:
        //             result.add(路径)
        //             return

        //         for 选择 in 选择列表:
        //             做选择
        //             backtrack(路径, 选择列表)
        //             撤销选择
        // option 1 O(2^N) time
        // if(nums.size()==0) return 0;
        // int ret =0;
        // backtrack(nums, 0, target, ret);
        // return ret;

        //option 2 memo 消除重疊子問題
        if (nums.size() == 0)
            return 0;
        unordered_map<string, int> memo;

        return dp(nums, 0, target, memo);
    }
};