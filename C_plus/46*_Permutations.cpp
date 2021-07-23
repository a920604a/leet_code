class Solution {
public:
    void generatePermute(vector<int>& nums, vector<int> out, vector<vector<int>> & ret){
        
        // backtrack 框架
        // void traverse(TreeNode root) {
        //     for (TreeNode child : root.childern)
        //         // 前序遍历需要的操作
        //         traverse(child);
        //         // 后序遍历需要的操作
        // }
        
        // for 选择 in 选择列表:
        //     # 做选择
        //     将该选择从选择列表移除
        //     路径.add(选择)
        //     backtrack(路径, 选择列表)
        //     # 撤销选择
        //     路径.remove(选择)
        //     将该选择再加入选择列表
        
        
        if(out.size()== nums.size()){
            ret.push_back(out);
            return ;
        }
        for(int i=0 ; i<nums.size();i++){
            // 排除不合法選擇
            if(find(out.begin(), out.end(), nums[i])!=out.end()) continue;
            // 做選擇
            out.push_back(nums[i]);
            // 進入下一層決策樹
            generatePermute(nums,out, ret);
            // 撤銷選擇
            out.pop_back();
            
        }
        
    }
    void generatePermute(vector<int>& nums, int start, vector<vector<int>> & ret){
        if(start == nums.size()){
            ret.push_back(nums);
            return ;
        }
        
        for(int i=start ;i<nums.size();++i){
            swap(nums[i], nums[start]);
            generatePermute(nums, start+1, ret);
            swap(nums[i], nums[start]);
            
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        // option 1 brute force solution
        // vector<vector<int>>  ret;
        // vector<int> out;
        // generatePermute(nums, out,ret);
        // return ret;
        
        // option 1.1 brute force solution - swap version
        // vector<vector<int>>  ret;
        // vector<int> out;
        // generatePermute(nums, 0,ret);
        // return ret;
        
        
        // option 1.2  iterative version
        
        vector<vector<int>>  ret(1);
        for(int n:nums){
            int size = ret.size();
            for(int i=0;i<size;++i){
                int len  = ret[i].size();
                for(int j=0;j<len;++j){
                    vector<int> temp = ret[i];
                    temp.insert( temp.begin()+ j, n);
                    ret.push_back(temp);
                }
                ret[i].push_back(n);
            }
        }
        return ret;
        // option 1.3 iterative version
//             vector<vector<int>> ret(1);
//             for(int n:nums){
//                 int size = ret.size();
//                 for(int i=0;i<size;++i){
//                     for(int j = 0;j<ret[i].size();++j){
//                         ret.push_back(ret[i]); // 複製原先陣列
//                         ret.back().insert(ret.back().begin()+j,n);// 將新數字加入複製出來陣列的第j個位置。
//                     }
//                     ret[i].push_back(n); // 原先陣列加入新數字至尾部
//                 }

//             }
//             return ret;
        
        // option 2 cheat
            // vector<vector<int>> ret;
            // sort(nums.begin(), nums.end());
            // ret.push_back(nums);
            // while(next_permutation(nums.begin(), nums.end())){
            //     ret.push_back(nums);
            // }
            // return ret;
    }
};