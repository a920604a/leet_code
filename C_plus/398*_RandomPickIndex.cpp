class Solution
{
private:
    vector<int> vec;

public:
    Solution(vector<int> &nums)
    {
        // option 1 水塘抽樣
        // 從S中抽取首k項放入「水塘」中
        // 對於每一個S[j]項（j ≥ k）：
        // 隨機產生一個範圍從0到j的整數r
        // 若 r < k 則把水塘中的第r項換成S[j]項
        vec = nums;
    }

    int pick(int target)
    {

        int cnt = 0, ret = -1;
        for (int i = 0; i < vec.size(); ++i)
        {
            if (vec[i] != target)
                continue;
            cnt++;
            if (rand() % cnt == 0)
                ret = i;
        }

        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */