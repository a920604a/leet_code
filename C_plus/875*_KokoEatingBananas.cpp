class Solution
{
public:
    int f(vector<int> &piles, int x)
    {
        // 定義：吃香蕉速度 x根 每小時，則需要 f(x) 小時吃完所有香蕉
        // f 隨著x增加 單調遞減, f(15) = 4, f(8) = 5, f(15) = 2
        //  piles = 3   6   7   11 , x = 15
        //  hours = 1   2   3   4

        //  piles = 3   6   7   11 , x =  8
        //  hours = 1   2   3   5

        //  piles = 3   6   7   11 , x =  2
        //  hours = 2   5   9   15

        int hours = 0;
        for (int i = 0; i < piles.size(); ++i)
        {
            hours += piles[i] / x;
            if (piles[i] % x > 0)
                hours++; // 不足一樣算一小時，意味著假設每小時只能吃2根，但此堆只剩ㄧ根，一樣要花一小時，且不能吃其它堆
        }
        return hours;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // 不像先前的二元搜尋法直接在x的值域[3,6,7,11]搜尋，在y的值域搜尋>
        // 所以left, right變數不再是維護索引，而是索引之值。
        // 1 <= piles[i] <= 1e+9
        // tips 合併冗余if 可增加效率
        //         int left = 1;
        //         int right = 1e+9 +1; // 因為搜尋空間是左閉右開，所以+1

        //         // f() 單調遞減，左側邊界 二元搜尋法

        //         while(left < right){
        //             // 假設 每小時吃mid 根香蕉
        //             int mid = left + (right- left)/2;
        //             cout<<mid<<" "<<f(piles, mid)<<endl;

        //             // f(piles, mid) 每小時吃mid個香蕉，共要多久吃完全部香蕉
        //             if(f(piles, mid) ==h ){
        //                 right = mid; // 因為左側邊界
        //             }
        //             // 因為 f() 單調遞減
        //             else if(f(piles, mid) > h ) left = mid +1;
        //             else if(f(piles, mid) < h ) right = mid;
        //         }
        //         return left;

        // option 1.1 improved
        int left = 1;
        int right = 1e+9 + 1; // 因為搜尋空間是左閉右開，所以+1

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int target = f(piles, mid);
            if (target <= h)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};