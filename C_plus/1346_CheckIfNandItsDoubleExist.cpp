class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        // option1 O(nlogn)
        //         set<int> s;
        //         for(int a:arr){
        //             if(s.find(a)!=s.end()) return true;
        //             if(a%2==0 ) {
        //                 s.insert(a/2);
        //             }
        //             s.insert(a*2);

        //         }
        //         return false;

        // option1 O(nlogn)
        set<int> s;
        for (int n : arr)
        {
            if (s.find(n * 2) != s.end() || (n % 2 == 0 && s.find(n / 2) != s.end()))
                return true;
            s.insert(n);
        }
        return false;
    }
};