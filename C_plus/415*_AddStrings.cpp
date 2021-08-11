class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string ret = "";
        int n = num1.size(), m = num2.size();
        int l = n - 1, r = m - 1;
        int carry = 0;
        while (l > -1 || r > -1 || carry)
        {
            int sum = carry;
            if (l > -1)
                sum += num1[l--] - '0';
            if (r > -1)
                sum += num2[r--] - '0';
            ret.insert(0, to_string(sum % 10));
            carry = sum / 10;
        }
        return ret;
    }
};