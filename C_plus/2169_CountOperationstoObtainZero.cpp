class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        // recursively
        // if(num1 == 0 || num2 == 0) return 0;
        // if(num1 == num2) return 1;
        // if(num1 > num2) return 1+countOperations(num1-num2, num2);
        // else return 1+countOperations(num1, num2-num1);

        if (num1 == 0 || num2 == 0)
            return 0;
        int step = 0;
        while (num1 != 0 && num2 != 0)
        {
            if (num1 > num2)
                num1 -= num2;
            else
                num2 -= num1;
            step++;
        }
        return step;
    }
};