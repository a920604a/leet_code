class Solution
{
public:
    string intToRoman(int num)
    {
        string u[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string t[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string h[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string th[] = {"", "M", "MM", "MMM"};

        string roman = th[num / 1000] + h[(num % 1000) / 100] + t[(num % 100) / 10] + u[num % 10];
        return roman;
    }
};