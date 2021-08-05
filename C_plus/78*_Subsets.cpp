class Solution
{
public:
    void backtrack(vector<int> &nums, int start, vector<int> &track, vector<vector<int> > &ret)
    {
        // 對ret 的更新其實是 preorder
        ret.push_back(track);
        for (int i = start; i < nums.size(); ++i)
        {
            // 做選擇
            track.push_back(nums[i]);
            // 回朔
            backtrack(nums, i + 1, track, ret);
            // 撤消選擇
            track.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int> &nums)
    {

        // option 1 Recursion
        // O(N * 2^N) time and O(N *2^N) space 包含 O(N) recursive function call stack
        // subsets([1,2,3]) = subset([1,2]) + [s.append(3) for s in subset([1,2]) ]
        // base case
        if (nums.empty())
            return {{}};
        // 把最後一個元素拿出來
        int n = nums.back();
        nums.pop_back();

        vector<vector<int> > ret = subsets(nums);

        int size = ret.size();
        for (int i = 0; i < size; ++i)
        {
            // 在之前的結果中追加
            ret.push_back(ret[i]);
            ret.back().push_back(n);
        }
        return ret;

        // option 2 DFS
        vector<vector<int> > ret;
        vector<int> track;
        backtrack(nums, 0, track, ret);
        return ret;

        // option 3 iterative
        // vector<vector<int> > ret;
        // ret.push_back({});
        // for (int n : nums)
        // {
        //     int s = ret.size();
        //     for (int j = 0; j < s; ++j)
        //     {
                // 1. 先新增變數儲存要增加到ret尾部的vector 2. 再將vector尾部加n 3. 將vector加入ret尾部
                // vector<int> tmp = ret[j];
                // tmp.push_back(n);
                // ret.push_back(tmp);

                // 1. ret尾部複製一份索引j的vector，再將其vector尾部加n
        //         ret.push_back(ret[j]);
        //         ret.back().push_back(n);
        //     }
        // }
        // return ret;
    }
};