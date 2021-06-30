class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> sta;
        int ret = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i)
        {

            if (sta.empty() || heights[sta.top()] < heights[i])
                sta.push(i);
            else
            {
                cout << "i: " << i << endl;
                while (!sta.empty() && heights[i] <= heights[sta.top()])
                {
                    int t = sta.top();
                    sta.pop();
                    if (sta.empty())
                        ret = max(ret, heights[t] * (i));
                    else
                        ret = max(heights[t] * (i - sta.top() - 1), ret);

                    cout << ret << endl;

                    // ret = max(ret , heights[t] * (sta.empty() ?i:(i-sta.top()-1)));
                }
                sta.push(i);
            }
        }
        return ret;
    }
};