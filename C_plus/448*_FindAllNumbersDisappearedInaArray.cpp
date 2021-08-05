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
        // option 2 O(N) time and O(1) space
        // 拜訪過的用index 取負號
        //index  1 2 3 4 5 6 7 8 9
        //val    1 2 3 4 5 6 7 8 9
            //   0  1   2   3   4   5   6   7
        //       4  3   2   7   8   2   3   1
        //       -4 -3   -2  -7  8   2   -3  -1
        vector<int> ret;
        for(int i=0;i<nums.size();++i){
            int idx = abs(nums[i])-1;
            
            if(nums[idx]>0) nums[idx] *=-1;
            
        }
        // for(int n:nums) cout<<n<<" ";
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0) ret.push_back(i+1);
        }
        return ret;

        
        
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