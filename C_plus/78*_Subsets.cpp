class Solution
{
public:
    vector<vector<int> > subsets(vector<int> &nums)
    {
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