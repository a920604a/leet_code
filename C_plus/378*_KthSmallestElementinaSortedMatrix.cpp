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

        // option 4 從左下角開始搜尋
    }
};