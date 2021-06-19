class Solution
{
public:
    int Nextnum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {

        //option 1 two pointer slow and fast
        //         int slow =n, fast =n;
        //         while(1){
        //             slow = Nextnum(slow);
        //             fast = Nextnum(fast);
        //             fast = Nextnum(fast);
        //             if(slow==1) return true;
        //             if(fast == slow) break;

        //         }
        //         return false;

        // option 2 use set to record alreay seen
        int m = n;
        set<int> s;
        while (m)
        {

            int sum = Nextnum(m);
            m = sum;
            if (s.find(m) != s.end())
                break;
            s.insert(m);
            if (m == 1)
                return true;
        }
        return false;
    }
};