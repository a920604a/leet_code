class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        // 維護兩組dp 一個放累積最大，一個放累積最小。
        // 注意，最小值可能乘以一個負數而變最大。
        // option 1 dp
        //        2 3 -2  4
        //max     2 6 -2  4
        //min     2 3 -12 -48

        // int m = nums.size();
        // vector<int> _max(m,0), _min(m,0);
        // _max[0] = nums[0];
        // _min[0] = nums[0];
        // int ret = nums[0];
        // for(int i=1;i<m;++i){
        //     _max[i] = max( max(_max[i-1]*nums[i], _min[i-1]*nums[i]), nums[i]);
        //     _min[i] = min( min(_max[i-1]*nums[i], _min[i-1]*nums[i]), nums[i]);
        //     ret = max(ret, _max[i]);
        // }
        // return ret;

        // option 2 用變數 簡化 dp

        int n = nums.size();
        int mn = nums[0], mx = nums[0];
        int ret = nums[0];
        for (int i = 1; i < n; ++i)
        {
            int prev_mn = mn;
            mn = min(nums[i], min(mx * nums[i], mn * nums[i]));
            mx = max(nums[i], max(mx * nums[i], prev_mn * nums[i]));
            ret = max(ret, mx);
        }
        return ret;
    }
};