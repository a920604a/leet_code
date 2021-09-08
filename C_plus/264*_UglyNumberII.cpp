class Solution
{
public:
    bool UglyNumber(int n)
    {
        while (n % 2 == 0)
            n /= 2;
        while (n % 3 == 0)
            n /= 3;
        while (n % 5 == 0)
            n /= 5;
        return n == 1;
    }
    int nthUglyNumber(int n)
    {
        // brute force => time out
        // int cnt = 0, i=0;
        // while(cnt<n){
        //     if(UglyNumber(i+1) ) {
        //         cnt++;
        //     }
        //     i++;
        // }
        // return i;

        // option heap O(nlogn) time
        priority_queue<int, vector<int>, greater<int> > pq;
        pq.push(1);
        for (int i = 1; i < n; ++i)
        {
            int t = pq.top();
            pq.pop();
            while (!pq.empty() && pq.top() == t)
                pq.pop();
            if (t < INT_MAX / 2)
                pq.push(t * 2);
            if (t < INT_MAX / 3)
                pq.push(t * 3);
            if (t < INT_MAX / 5)
                pq.push(t * 5);
        }
        return pq.top();


        // option 2 dp O(n) time
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        vector<int> dp(n, 0);
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        
        //2*    1   1   2   2   3   4   4   5   6
        //3*    0   1   1   1   2   2   3   3   4
        //5*    0   0   0   1   1   1   1   2   2
        //dp    2   3   4   5   6   8   9   10  12
        //   
        
        dp[0] = 1;
        for(int i=1;i<n ;++i){
            dp[i] = min(dp[t2]*2, min(dp[t3]*3, dp[t5]*5) );            
            if(dp[i]==dp[t2]*2) t2++;
            if(dp[i]==dp[t3]*3) t3++;
            if(dp[i]==dp[t5]*5) t5++;
        }
        return dp.back();
    }
};