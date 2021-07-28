class Solution
{
public:
    int f(vector<int> &weights, int x)
    {
        // 定義：當運載能力為x 時，需要f(x)天才能完成運完所有貨物
        // f(weights, 10) = 7 , f(weights, 12) = 6
        // 隨著x 增加，f() 越小，單調遞增函數
        //       1   2   3   4  |  5 | 6 |  7  | 8 |  9 |  10 |
        //         days = 1     |  2 | 3 |  4  | 5 |  6 |   7 | ,  x= 10
        //         days = 1     |   2    |  3  | 4 |  5 |   6 | ,  x= 12

        int days = 0;

        for (int i = 0; i < weights.size();)
        {
            int cap = x;

            while (i < weights.size())
            {
                if (cap < weights[i])
                    break;
                else
                    cap -= weights[i];
                i++;
            }
            days++;
        }

        return days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {

        // 左側邊界 二元搜尋
        // 初始化left, right
        // 船的最小載重 是 貨物最大值，最大載重一定是 所有貨物總重
        int left = 0, right = 1;
        for (int w : weights)
        {
            left = max(left, w);
            right += w;
        }
        while (left < right)
        {
            // 一開始假設 1 + (501-1)/2 = 船的容量 251，則一天就可以元算完，
            // 迭代式逼近 預估天數小於等於 days
            // 假設船的容量是mid，則需要f(weights, mid)天可運完。
            int mid = left + (right - left) / 2;
            int evalDays = f(weights, mid);
            if (evalDays <= days)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};