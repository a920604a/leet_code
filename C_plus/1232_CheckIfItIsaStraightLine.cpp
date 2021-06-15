/*
 * @Author: yuan
 * @Date: 2021-05-05 16:59:51
 * @LastEditTime: 2021-05-05 16:59:59
 * @FilePath: /C_plus/1232_CheckIfItIsaStraightLine.cpp
 */
class Solution
{
public:
    bool checkStraightLine(vector<vector<int> > &coordinates)
    {
        if (coordinates.size() == 2)
            return true;

        int m1 = coordinates[1][1] - coordinates[0][1];
        int m2 = coordinates[1][0] - coordinates[0][0];
        for (int i = 2; i < coordinates.size(); ++i)
        {
            if ((coordinates[i][1] - coordinates[0][1]) * m2 != m1 * (coordinates[i][0] - coordinates[0][0]))
                return false;
        }
        return true;
    }
};