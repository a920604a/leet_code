class Solution
{
public:
    int intervalSchedule(vector<vector<int> > &intervals)
    {
        // step1. 將intervals用end升序排列
        // step2. 選擇一個區間x，他結束時間是最早的
        // step3. 把所有與x區間相交的都移除
        // step4. 重複2、3步驟，直到intervals為空。將之前選出的x就是最大不相交子集。

        if (intervals.size() == 0)
            return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
             { return a[1] < b[1]; });

        vector<int> ret;
        int count = 1;
        int x_end = intervals[0][1];
        for (vector<int> interval : intervals)
        {
            int start = interval[0];
            if (start >= x_end)
            {
                count++;
                x_end = interval[1];
            }
        }
        return count;
    }
    int eraseOverlapIntervals(vector<vector<int> > &intervals)
    {
        // 貪心演算法，每一步都取局部最佳解，最終結果會是全局最佳解。
        // 貪心演算法可以視為動態規劃的一個特例，需滿足更多條件。
        // 暴力法一般需要指數級時間、如果使用動態規劃消除子問題可以達到多項式級別的時間、滿足貪心選擇性質則可以達到線性級別時間

        // step1. 將intervals用end升序排列
        // step2. 選擇一個區間x，他結束時間是最早的
        // step3. 把所有與x區間相交的都移除
        // step4. 重複2、3步驟，直到intervals為空。將之前選出的x就是最大不相交子集。
        // step5. intervals長度減去最大不相交子集長度即為答案。

        return intervals.size() - intervalSchedule(intervals);
    }
};