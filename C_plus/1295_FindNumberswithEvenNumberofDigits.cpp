class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        // option 1 Intuitive
        // int ret = 0;
        // for(int n:nums){
        //     int c= 0;
        //     while(n){
        //         n /=10;
        //         c++;
        //     }
        //     ret +=(c%2==0)?1:0;
        // }
        // return ret;

        // option 2 tricky ? cheat?
        // cause <=10^5
        // 1~9 : 1 , 10~99 : 2
        // 100~999:3 , 1000~9999 : 4
        // 10000~99999:5 , 100000:5
        // int ret = 0;
        // for(int n:nums){
        //     if( (n>=10 && n<=99) || (n>=1000 && n<=9999) || n==100000) ret++;
        // }
        // return ret;

        // option 3 log10
        // 1~9、100~999、10000~99999 log10 = [0,1)、[2,3)、[4,5) = int(x) = 0、2、4
        // 10~99、1000~9999、100000 log10 = [1,2)、[3,4)、5 = int(x) = 1、3、5
        // int ret=0;
        // for(int n:nums){
        //     ret += (int)log10(n)&1;
        // }
        // return ret;

        // option 4 convert string and compute length
        int ret = 0;
        for (int n : nums)
            ret += (to_string(n).size() % 2 == 0) ? 1 : 0;
        return ret;
    }
};