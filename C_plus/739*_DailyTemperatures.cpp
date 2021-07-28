class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // option 1 順向 monotonic stack
        stack<int> sta;
        int size = temperatures.size();
        vector<int> ret(size, 0);
        for (int i = 0; i < size; ++i)
        {
            while (!sta.empty() && temperatures[i] > temperatures[sta.top()])
            {
                int t = sta.top();
                sta.pop();
                ret[t] = i - t;
            }
            sta.push(i);
        }
        return ret;

        //option 2 monotonic stack 逆向
        int size = temperatures.size();
        // 放元素索引
        vector<int> ret(size);
        stack<int> sta;
        
        for(int i=size-1 ;i>-1;i--){
            
            while(!sta.empty() && temperatures[sta.top()] <= temperatures[i]){
                sta.pop();
            }
            // 索引差距
            ret[i] = sta.empty()? 0 : (sta.top()-i);
            sta.push(i);
            
        }
        return ret;

    }
};