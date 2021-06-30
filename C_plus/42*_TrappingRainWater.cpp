class Solution
{
public:
    int trap(vector<int> &height)
    {
        // optnio 1 stack

        //         stack<int> sta; //存索引 單調堆疊
        //         int ret=0;
        //         for(int i=0;i<height.size();){
        //             if( sta.empty() || height[i] <= height[sta.top()] ){
        //                 sta.push(i++);
        //             }
        //             else{ // the current height 比 sta.top 大
        //                 int t = sta.top(); // 坑的底
        //                 sta.pop();
        //                 if(sta.empty()) continue; // 不夠形成坑
        //                 ret +=    (min(height[i], height[sta.top()]) - height[t]) * (i - sta.top() -1 );
        //                 // ret +=    (min(height[i], height[sta.top()]) - height[t]) * (i - sta.top() - 1);
        //                 // 高(剪掉坑的高度) 乘 寬(索引相剪)
        //                 cout<<ret<<endl;

        //             }
        //         }
        //         return ret;

        // option 2 dynamic programming
        int n = height.size(), ret = 0;
        vector<int> dp(n, 0);
        int _max = -1;
        for (int i = 1; i < n - 1; ++i)
        {
            _max = max(_max, height[i - 1]);
            dp[i] = _max;
        }
        for (int i : dp)
            cout << i << " ";
        cout << endl;
        _max = -1;
        for (int i = n - 2; i > 0; i--)
        {
            _max = max(_max, height[i + 1]);
            dp[i] = min(dp[i], _max);
        }
        for (int i : dp)
            cout << i << " ";
        cout << endl;

        for (int i = 0; i < n; ++i)
        {
            if (height[i] < dp[i])
                ret += (dp[i] - height[i]);
        }

        return ret;

        // optnio 3 two pointers
    }
};