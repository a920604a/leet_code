class Solution
{
public:
    vector<vector<int> > intervalIntersection(vector<vector<int> > &firstList, vector<vector<int> > &secondList)
    {

        // 畫圖分析
        // 假設兩個區間 [a1, a2] [b1, b2]
        // 情況一：沒交集 例 [3,4] [5,6]
        // 情況二之一：有交集，且覆蓋區間 例 [3,6] [2,5] , 交集區間[3, 5]
        // 情況二之二：有交集， 例 [1,3] [2,5]   , 交集區間[2, 3]
        // 情況二之三：有交集，且覆蓋區間 例 [2,5] [3,6] , 交集區間[3, 5]
        // 情況二之四：有交集， 例 [2,5] [1,3]  , 交集區間[2, 3]
        // 假設交集區間為 [c1, c2], c1 = max(a1, b1) , c2 = min(a2, b2)，得知這可以大幅簡化

        vector<vector<int> > ret;
        int l = 0, r = 0;
        int n = firstList.size(), m = secondList.size();
        while (l < n && r < m)
        {
            int a1 = firstList[l][0], a2 = firstList[l][1];
            int b1 = secondList[r][0], b2 = secondList[r][1];

            // 有交集，情況二
            if (b2 >= a1 && a2 >= b1)
            {
                ret.push_back({max(a1, b1), min(a2, b2)});
            }

            // 指針前進
            if (b2 < a2)
                r++;
            else
                l++;
        }
        return ret;
    }
};