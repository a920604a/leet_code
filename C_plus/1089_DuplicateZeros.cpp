class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        // option 1  use STL queue O(n)
        queue<int> q;
        for (int i = 0; i < arr.size(); ++i)
        {
            q.push(arr[i]);
            if (arr[i] == 0)
                q.push(arr[i]);
            arr[i] = q.front();
            q.pop();
        }

        // option 2 cheat  O(n) time  O(n) space
        //         vector<int> ret;
        //         int n =arr.size();
        //         for(int i=0;i<n && ret.size()<n ;++i){
        //             ret.emplace_back(arr[i]);
        //             if(arr[i] == 0 && ret.size() < n) ret.push_back(0);
        //         }

        //         arr = ret;

        // option 3 use vector insert and erase to dynamically resize

        // int number_zeros = 0;
        // for(int a:arr) number_zeros += (a==0?1:0);
        // int i=0;
        // while(number_zeros &&  i<arr.size()){
        //     if(arr[i]==0){
        //         arr.insert(arr.begin()+i,0);
        //         number_zeros--;
        //         i++;
        //         arr.erase(arr.end()-1);
        //     }
        //     i++;
        // }
    }
};