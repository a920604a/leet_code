class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        // option 1 O(sqrt(n))
        //         for(int i =1;i<=num/i;i++){
        //             if(i*i==num) return true;
        //         }
        //         return false;

        // option 2 O(sqrt(n))
        // 1 = 1
        // 4 = 1 + 3
        // 9 = 1 + 3 + 5
        // 16 = 1 + 3 + 5 + 7
        // 25 = 1 + 3 + 5 + 7 + 9
        int i = 1;
        while (num > 0)
        {
            num -= i;
            i += 2;
        }
        return num == 0;

        // option 3 binary search
    }
};