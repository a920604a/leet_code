class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // option 1 O(n) space O(n) time
        // int m = nums.size();
        // vector<int> left (m,1), right(m,1);
        // for(int i =1;i<m;++i){
        //     left[i] = left[i-1] * nums[i-1];
        // }
        // for(int i=m-2;i>=0;i--){
        //     right[i] = right[i+1] * nums[i+1];
        // }
        // vector<int> ret(m,1);
        // for(int i=0;i<m;++i) ret[i]= left[i]*right[i];
        // return ret;
        
        
        // option 2 O(n) time, O(1) space
        // maske use of the return's vector again.
        int m = nums.size();
        vector<int> ret(m,1);
        for(int i=1;i<m;++i){
            // 先將ret 當作 left
            ret[i] = ret[i-1] *nums[i-1];
        }
        int right = 1;
        for(int i=m-1;i>-1;--i){
            ret[i] = ret[i]*right;
            right = right * nums[i];
        }
        return ret;
        
        
    }
};