class Difference
{
private:
    vector<int> diff;

public:
    Difference(vector<int> &nums)
    {
        diff = vector<int>(nums.size(), 0);
        // 建造差分數組
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            diff[i] = nums[i] - nums[i - 1];
        }
    }
    void increment(int i, int j, int val)
    {
        // 給閉區間 [i, j] 增加 val 可以是負數
        diff[i] += val;
        // 相當於 inded = i 後的元素的 加val
        if (j + 1 < diff.size())
        {
            diff[j + 1] -= val;
        }
        // 相當於 inded = j+1 後的元素的 剪val
    }
    vector<int> result()
    {
        // 根據差分數組建造結果數組
        vector<int> ret(diff.size(), 0);
        ret[0] = diff[0];
        for (int i = 1; i < diff.size(); i++)
        {
            ret[i] = ret[i - 1] + diff[i];
        }
        return ret;
    }
};

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int> > &bookings, int n)
    {
        // option
        // 差分 主要場景適用頻繁的對原數組的某區間的元素進行增減。
        // [1,2,10],[2,3,20],[2,5,25]
        // 還原數組 => 10 55 45 25 25
        // option 1 timeout O(n^2)
        //         vector<int> ret(n,0);
        //         for(auto vec:bookings){
        //             int l = vec[0], r = vec[1], k = vec[2];
        //             for(int i=l;i<=r;++i){
        //                 ret[i-1] += k;
        //             }
        //         }
        //         return ret;

        // option 2
        vector<int> num(n, 0);
        Difference *diff = new Difference(num);
        for (vector<int> book : bookings)
        {
            int i = book[0] - 1;
            int j = book[1] - 1;
            int val = book[2];
            diff->increment(i, j, val);
        }
        return diff->result();
    }
};