// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

bool isValid(string &s)
{
    int letter = 0, num = 0;
    for (char c : s)
    {
        // include invalid character
        if (isalnum(c) == 0)
            return false;
        if (isalpha(c) != 0)
            letter++;
        else if (c - '0' >= 0 && c - '0' <= 9)
            num++;
    }
    return ((letter) % 2 == 0 && (num % 2 != 0)) ? true : false;
}
int solution(string &S)
{
    // write your code in C++14 (g++ 6.2.0)

    vector<string> passwords;
    //split words
    int n = S.size();
    // special case
    if (n == 1)
    {
        if (S[0] - '0' >= 0 && S[0] - '0' <= 9)
            return 1;
        return -1;
    }

    int i = 0;
    while (i < n && S[i] == ' ')
        i++;
    string word;
    while (i < n)
    {
        if (S[i] == ' ')
        {
            passwords.push_back(word);
            word = "";
        }
        else
        {
            word += S[i];
        }
        i++;
    }
    if (!word.empty())
        passwords.push_back(word);

    int ret = -1;
    for (string str : passwords)
    {
        if (!isValid(str))
            continue;
        ret = max(ret, (int)str.size());
    }
    return ret;
}
