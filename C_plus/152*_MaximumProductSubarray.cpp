class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        // 維護兩組dp 一個放累積最大，一個放累積最小。
        // 注意，最小值可能乘以一個負數而變最大。
        // option 1 dp
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
        int m = nums.size();
        int _max = nums[0];
        int _min = nums[0];
        int ret = nums[0];
        for (int i = 1; i < m; ++i)
        {
            int tmax = _max, tmin = _min;
            _max = max(max(tmax * nums[i], tmin * nums[i]), nums[i]);
            _min = min(min(tmax * nums[i], tmin * nums[i]), nums[i]);
            ret = max(ret, _max);
        }
        return ret;
    }
};