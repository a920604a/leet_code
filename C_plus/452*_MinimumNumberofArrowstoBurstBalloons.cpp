class Solution
{
public:
    int intervalSchedule(vector<vector<int> > &points)
    {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b)
             {
            return a[1]<b[1]; // end升序 });

        int x_end = points[0][1];
        int count = 1;
        for (vector<int> point : points)
        {
            int x_start = point[0];
            if (x_start > x_end)
            {
                count++;
                x_end = point[1];
            }
        }
        return count;
    }
    int findMinArrowShots(vector<vector<int> > &points)
    {
        // 貪心演算法，每一步都取局部最佳解，最終結果會是全局最佳解。
        // 貪心演算法可以視為動態規劃的一個特例，需滿足更多條件。
        // 暴力法一般需要指數級時間、如果使用動態規劃消除子問題可以達到多項式級別的時間、滿足貪心選擇性質則可以達到線性級別時間

        // 有幾個不重疊區間

        return intervalSchedule(points);
    }
};