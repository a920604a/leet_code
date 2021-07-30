class Solution
{
public:
    bool isRectangleCover(vector<vector<int> > &rectangles)
    {

        // option 最終形成的圖形有多少頂點，就能判斷最終圖形是不是完美矩形
        // 當某點同時是 2 個 或 4 個矩形的頂點時，該點最終不是頂點。
        // (X1, Y1) 左下角頂點 (X2, Y2) 右上角頂點
        int X1 = INT_MAX, Y1 = INT_MAX;
        int X2 = INT_MIN, Y2 = INT_MIN;
        // 用集合紀錄最終圖形的頂點
        set<tuple<int, int> > points;
        // 所有小矩形面積
        int actual_area = 0;
        for (vector<int> r : rectangles)
        {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            X1 = min(X1, x1);
            Y1 = min(Y1, y1);
            X2 = max(X2, x2);
            Y2 = max(Y2, y2);
            actual_area += (x2 - x1) * (y2 - y1);

            // 對於每個點，如果存在集合中，則刪除他。 如果不存在集合中，添加他
            // 在集合中剩下的點都是出現奇數次的點
            // 记录最终形成的图形中的顶点
            vector<tuple<int, int> > pts = {
                make_tuple(x1, y1),
                make_tuple(x1, y2),
                make_tuple(x2, y1),
                make_tuple(x2, y2)};
            for (tuple<int, int> pt : pts)
            {
                if (points.find(pt) != points.end())
                    points.erase(pt);
                else
                    points.insert(pt);
            }
        }

        // 計算完美矩形的理論面積
        int expected_area = (X2 - X1) * (Y2 - Y1);
        // 面積應該相同
        if (actual_area != expected_area)
        {
            return false;
        }
        // 判断最终留下的顶点个数是否为 4
        if (points.size() != 4)
            return false;
        // 判断留下的 4 个顶点是否是完美矩形的顶点
        if (points.find(make_tuple(X1, Y1)) == points.end())
            return false;
        if (points.find(make_tuple(X1, Y2)) == points.end())
            return false;
        if (points.find(make_tuple(X2, Y1)) == points.end())
            return false;
        if (points.find(make_tuple(X2, Y2)) == points.end())
            return false;

        return true;
    }
};