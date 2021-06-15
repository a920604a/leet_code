/*
 * @Author: yuan
 * @Date: 2021-04-29 15:55:57
 * @LastEditTime: 2021-04-29 15:55:58
 * @FilePath: /C_plus/168_ExcelSheetColumnTitle.cpp
 */
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ret = "";
        char tmp;
        while (columnNumber)
        {
            columnNumber--;
            tmp = (columnNumber % 26) + 'A';
            ret = tmp + ret;
            columnNumber /= 26;
        }
        return ret;
    }
};