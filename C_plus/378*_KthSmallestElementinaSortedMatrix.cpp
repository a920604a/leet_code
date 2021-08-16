class Solution
{
public:
    int kthSmallest(vector<vector<int> > &matrix, int k)
    {

        // option 1 brute O(n^3) -> time limited
        // flatten and insert sort
        //         int m=matrix.size(), n=matrix[0].size();
        //         vector<int> vec(matrix[0].begin(), matrix[0].end());

        //         for(int i=1;i<m;++i){
        //             for(int a:matrix[i]){
        //                 vec.emplace_back(a);

        //                 int j = vec.size()-2;
        //                 while(j>-1 && vec[j] >a){
        //                     vec[j+1] = vec[j];
        //                     j--;
        //                 }
        //                 vec[j+1] = a;
        //             }
        //         }

        //         return vec[k-1];

        // option 2
        // search matrix
        // [1    5   90]
        // [10  13  130]
        // [12  103 150] , k=4
        // use STL
        //         priority_queue<int,vector<int>,greater<int> > q; // 最小的優先取出
        //         int m =matrix.size(), n=matrix[0].size();

        //         for(int i=0;i<m;++i){
        //             for(int j =0;j<n;++j) q.push(matrix[i][j]);  // O(n^2 logn)
        //         }
        //         k--;
        //         while(k){
        //             q.pop();
        //             k--;
        //         }
        //         return q.top();

        // option 3 binary search
        int left = matrix[0][0], right = matrix.back().back();
        // 左側邊界 二元搜尋
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (int i = 0; i < matrix.size(); ++i)
            {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                // upper_bound 找出大於 val 的最小位置
            }
            // 第一個元素大於 mid 8 的位置 2, 索引從 1 開始 => 小於 mid=8 數字有2個
            // 第一個元素大於 mid 12 的位置 6
            // 遍歷完，可以找出mid 中間數，是第幾小的數字
            if (cnt == k)
                right = mid;
            else if (cnt < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};