class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {

        // brute force => time out
        // int ret = 0, n = values.size();
        // for(int i=0;i<n-1;++i){
        //     for(int j = i+1;j<n;++j){
        //         ret = max(ret, values[i] + values[j] + i-j );
        //     }
        // }
        // return ret;

        // option 1
        int mx = 0, n = values.size(), ret = 0;
        for (int i = 0; i < n; ++i)
        {
            ret = max(ret, mx + values[i] - i);
            mx = max(mx, values[i] + i);
        }
        return ret;
    }
};