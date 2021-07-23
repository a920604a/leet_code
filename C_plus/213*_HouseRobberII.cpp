class Solution {
public:
    int rob(vector<int> & nums, int start, int end){
        
        int a = nums[start];
        if(end-start+1==1) return a;
        int b = max(nums[start+1], a);
        int ret = 0;
        for(int i = start+2;i<=end;++i){
            ret = max(a+nums[i], b);
            a = b;
            b = ret;
        }
        return max(ret, b);
        
        
    }
    int rob(vector<int>& nums) {
        // option 1 因為只會發生兩種情況。
        // 從第一家開始搶，就不能搶第 n-1
        // 從第二家開始搶，就可以一直搶下去
        int n =nums.size();
        if(n==1) return nums[0];
        return max(rob(nums, 0, n-2), rob(nums, 1,n-1));
        
    }
};