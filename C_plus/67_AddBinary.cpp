class Solution
{
public:
    string addBinary(string a, string b)
    {

        int len = max(a.size(), b.size());
        for (int i = a.size(); i < len; ++i)
            a = "0" + a;
        for (int i = b.size(); i < len; ++i)
            b = "0" + b;

        int sum = 0;
        int carry = 0;
        string ret = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 || j >= 0)
        {
            sum = carry;
            sum += a[i--] - '0';
            sum += b[j--] - '0';

            if (sum >= 2)
                carry = sum / 2;
            else
                carry = 0;
            // if(sum==3){
            //     carry = sum/2;
            // }
            // else if(sum==2){
            //     carry = sum/2;
            // }
            // else if(sum==1){
            //     carry = 0;
            // }
            // else if(sum==0){
            //     carry = 0;
            // }
            ret = to_string(sum % 2) + ret;
        }
        if (carry > 0)
        {
            ret = to_string(carry % 2) + ret;
        }
        return ret;
    }
};