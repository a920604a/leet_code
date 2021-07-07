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
        // option 1
        // vector<vector<int>>  ret(1);
        // for(int n:nums){
        //     int size = ret.size();
        //     for(int i=0;i<size;++i){
        //         int len  = ret[i].size();
        //         for(int j=0;j<len;++j){
        //             vector<int> temp = ret[i];
        //             temp.insert( temp.begin()+ j, n);
        //             ret.push_back(temp);
        //         }
        //         ret[i].push_back(n);
        //     }
        // }
        // return ret;

        // option 1.1 improved
        //         vector<vector<int>> ret(1);
        //         for(int n:nums){
        //             int size = ret.size();
        //             for(int i=0;i<size;++i){
        //                 for(int j = 0;j<ret[i].size();++j){
        //                     ret.push_back(ret[i]); // 複製原先陣列
        //                     ret.back().insert(ret.back().begin()+j,n);// 將新數字加入複製出來陣列的第j個位置。
        //                 }
        //                 ret[i].push_back(n); // 原先陣列加入新數字至尾部
        //             }

        //         }
        //         return ret;

        // option 2
        //         vector<vector<int>> ret;
        //         permuteDFS(nums, 0, ret);
        //         return ret;

        // option 3 cheat
        //         vector<vector<int>> ret;
        //         sort(nums.begin(), nums.end());
        //         ret.push_back(nums);
        //         while(next_permutation(nums.begin(), nums.end())){
        //             ret.push_back(nums);
        //         }
        //         return ret;
    }
};