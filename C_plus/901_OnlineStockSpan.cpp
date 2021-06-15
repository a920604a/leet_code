/*
 * @Author: yuan
 * @Date: 2021-05-04 18:51:52
 * @LastEditTime: 2021-05-04 18:51:52
 * @FilePath: /C_plus/901_OnlineStockSpan.cpp
 */
class StockSpanner
{
public:
    // vector<int> ret;
    stack<pair<int, int> > s;

    StockSpanner()
    {
    }

    int next(int price)
    {
        // int res =0;
        // ret.push_back(price);
        // for(int i=ret.size()-1;i>-1;i--){
        //     if(price >= ret[i]) res++;
        //     else break;
        // }
        // return res;

        int res = 1;
        while (!s.empty() && s.top().first <= price)
        {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */