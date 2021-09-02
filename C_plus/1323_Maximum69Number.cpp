class Solution
{
public:
    int maximum69Number(int num)
    {
        // option 1
        // 從左邊開始第一個六換成九。
        // int ret = 0;
        // while(num){
        //     ret = 10*ret + (num%10);
        //     num /=10;
        // }
        // bool f = true;
        // int i=-1;
        // int n = ret;
        // int ans = 0;
        // while(n){
        //     if((n%10)==6  && f){
        //         f = false;
        //         ans = 10*ans +9;
        //     }
        //     else ans = 10*ans + (n%10);
        //     n/=10;
        // }
        // return ans;

        // option 2
        string s = to_string(num);
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '6')
            {
                s[i] = '9';
                return stoi(s);
            }
        }
        return num;
    }
};