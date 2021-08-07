class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int> > &intervals)
    {
        // 區間問題，主要技巧有二
        // 1. 排序：按照區間起點做升序排序，如果起點相同則用終點降序排序
        // 2. 畫圖：分析兩區間相對位置有多少種可能。

        // 計算覆蓋區間有多少個，在用區間總數減去就是剩餘區間數

        // 兩區間相對位置有三種可能
        // 1. 覆蓋區間                    例 [1,6] [2,5]
        // 2. 兩區間可以合併，形成一個大區間  例 [1,3] [2,5] => [1,5]
        // 3. 兩區間不相交                 例 [1,2] [10,12]

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1]; //終點降序排序
                 return a[0] < b[0];     // 起點做升序排序
             });

        // 紀錄合併區間起點及終點
        int start = intervals[0][0], end = intervals[0][1];
        int ret = 0;
        for (int i = 1; i < intervals.size(); ++i)
        {
            vector<int> cur = intervals[i];

            // 情況一，覆蓋區間
            if ( end >= cur[1])
            {
                ret++;
            }
            // 情況二，兩區間可以合併，形成一個大區間
            else if ( cur[0] <= end && end <= cur[1])
            {
                // 因為  cur[0] 大於等於 start，因為有排序
                end = cur[1];
            }
            // 情況三，兩區間不相交
            else if (end < cur[0])
            {
                // 前進
                start = cur[0];
                end = cur[1];
            }
        }
        return intervals.size() - ret;
    }
};