class Solution
{
public:
    void getSubsets(vector<int> &nums, int idx, vector<vector<int> > &ret, vector<int> &cand)
    {

        ret.push_back(cand);

        for (int i = idx; i < nums.size(); ++i)
        {
            cand.push_back(nums[i]);
            getSubsets(nums, i + 1, ret, cand);
            cand.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int> &nums)
    {

        // option 1 Recursion
        vector<vector<int> > ret;
        vector<int> cand;
        getSubsets(nums, 0, ret, cand);
        return ret;

        // option 2 iterative
        vector<vector<int> > ret;
        ret.push_back({});
        for (int n : nums)
        {
            int s = ret.size();
            for (int j = 0; j < s; ++j)
            {
                // 1. 先新增變數儲存要增加到ret尾部的vector 2. 再將vector尾部加n 3. 將vector加入ret尾部
                // vector<int> tmp = ret[j];
                // tmp.push_back(n);
                // ret.push_back(tmp);

                // 1. ret尾部複製一份索引j的vector，再將其vector尾部加n
                ret.push_back(ret[j]);
                ret.back().push_back(n);
            }
        }
        return ret;
    }
};