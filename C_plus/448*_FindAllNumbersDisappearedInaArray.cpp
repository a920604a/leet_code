class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // option 1 O(nlogn)
        // vector<int> ret;
        // sort(nums.begin(), nums.end());
        // vector<int> tmp (nums.size()+1,0);
        // for(int i:nums) tmp[i]++;
        // for(int i=1;i<tmp.size();++i){
        //     if(tmp[i]==0) ret.push_back(i);
        // }
        // return ret;
        
        //option 2 O(n) without extra space
        // each number is postive , can use 相反數, 座標及數值間相互轉換
//         vector<int> ret;
//         for(int i=0;i<nums.size();++i){
//             int idx = abs(nums[i])-1;
//             nums[idx] = nums[idx]>0? -nums[idx]:nums[idx];
//         }
        
//         // select postive, 代表該索引是答案
//         for(int i=0;i<nums.size();++i){
//             if(nums[i]>0) ret.push_back(i+1);
//         }
//         return ret;
        
        // option 3 O(n) without extra space
        // 座標及數值間相互轉換 + 排序
        vector<int> ret;
        for(int i=0;i<nums.size();++i){
            
            if(nums[i]!=nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
                i--;
            }
        }
        
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=i+1) ret.push_back(i+1);
        }
        return ret;
        
    }
};