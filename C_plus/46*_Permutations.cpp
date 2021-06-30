class Solution
{
public:
    void permuteDFS(vector<int> &num, int start, vector<vector<int> > &res)
    {
        if (start >= num.size())
            res.push_back(num);
        for (int i = start; i < num.size(); ++i)
        {
            swap(num[start], num[i]);
            permuteDFS(num, start + 1, res);
            swap(num[start], num[i]);
        }
    }
    vector<vector<int> > permute(vector<int> &nums)
    {
        // option 1 brute force O(n!) time

        // vector<vector<int>> res(1);
        // for(int n:nums) {
        //     int s = res.size();
        //     for(int i=0;i<s;i++) {
        //         for(int j=0;j<res[i].size();j++) {
        //             res.push_back(res[i]); // 複製原先陣列
        //             res.back().insert(res.back().begin()+j,n); // 將新數字加入複製出來陣列的第j個位置。
        //         }
        //         res[i].push_back(n);// 原先陣列加入新數字至尾部
        //     }
        // }
        // return res;

        // option 2 DFS
        // vector<vector<int>> ret;
        // permuteDFS(nums, 0, ret);
        // return ret;

        // option 3 cheat
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        ret.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()))
        {
            ret.push_back(nums);
        }
        return ret;
    }
};