class StockSpanner
{
public:
    // vector<int> ret; // option 1
    stack<pair<int, int> > s; // option 2
    StockSpanner()
    {
    }

    int next(int price)
    {
        // option 1 maintain vector O(n) time
        // int res =0;
        // ret.push_back(price);
        // for(int i=ret.size()-1;i>-1;i--){
        //     if(price >= ret[i]) res++;
        //     else break;
        // }
        // return res;

        // option 2 maintain stack
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