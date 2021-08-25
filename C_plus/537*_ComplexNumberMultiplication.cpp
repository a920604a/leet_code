class Solution
{
public:
    string complexNumberMultiply(string num1, string num2)
    {
        int n1 = num1.size(), n2 = num2.size();
        auto p1 = num1.find_last_of("+"), p2 = num2.find_last_of("+");
        int a1 = stoi(num1.substr(0, p1)), b1 = stoi(num2.substr(0, p2));
        int a2 = stoi(num1.substr(p1 + 1, n1 - p1 - 2));
        int b2 = stoi(num2.substr(p2 + 1, n2 - p2 - 2));
        int r1 = a1 * b1 - a2 * b2, r2 = a1 * b2 + a2 * b1;
        return to_string(r1) + "+" + to_string(r2) + "i";
    }
};