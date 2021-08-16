class Solution
{
public:
    string toHex(int num)
    {
        string ret, hex = "0123456789abcdef";
        unsigned int x = num;
        while (x > 0)
        {
            ret = hex[x % 16] + ret;
            x /= 16;
        }
        return ret.empty() ? "0" : ret;

        // bit manuipulation
        // string ret, str= "0123456789abcdef";
        // int cnt = 0;
        // while (num != 0  && cnt++ < 8){
        // // for(int i =0;i<8;++i){
        //     ret = str[num& 15]+ret;
        //     num >>=4;
        // }
        // return ret==""? "0": ret;
    }
};