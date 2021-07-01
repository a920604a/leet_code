class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        // option 1 O(n^2) brute force
        // int n= nums.size();
        // vector<int> ret(n,0);
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<n;++j){
        //         if(i==j) continue;
        //         ret[i] +=(nums[j]<nums[i])?1:0;
        //     }
        // }
        // return ret;

        // option 2 O(n) improve using histogram
        int n = nums.size();
        vector<int> vec(101, 0);
        vector<int> ret(n, 0);
        int _min = 100, _max = 0;
        for (int m : nums)
        {
            vec[m]++;
            _min = min(m, _min);
            _max = max(m, _max);
        }
        int total = 0, pre = 0;
        for (int i = _min; i <= _max; ++i)
        {
            pre = vec[i];
            vec[i] = total;
            total += pre;
        }

        for (int i = 0; i < n; ++i)
        {
            ret[i] = vec[nums[i]];
        }
        return ret;
    }
};