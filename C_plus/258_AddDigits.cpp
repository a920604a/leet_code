class Solution
{
public:
    int addDigits(int num)
    {
        // option 1
        //         int m = num;
        //         while(m>=10){

        //             int sum = 0;
        //             while(m){
        //                 sum += m%10;
        //                 m/=10;
        //             }
        //             m=sum;
        //         }
        //         return m;

        // option 2
        // without any loop/recursion
        // 1-9 => 1-9
        // 10-18 => 1-9
        // 19-27 => 1-9
        // 28-36 => 1-9
        if (n == 0)
            return 0;
        return (num - 1) % 9 + 1;
    }
};