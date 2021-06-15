/*
 * @Author: yuan
 * @Date: 2021-05-04 17:27:00
 * @LastEditTime: 2021-05-04 17:27:00
 * @FilePath: /C_plus/733_FloodFill.cpp
 */
class Solution
{
public:
    void fill(vector<vector<int> > &image, int i, int j, int color, int newColor)
    {
        if (i < 0 || i > image.size() - 1 || j < 0 || j > image[0].size() - 1 || image[i][j] != color)
            return;
        image[i][j] = newColor;
        fill(image, i - 1, j, color, newColor);
        fill(image, i + 1, j, color, newColor);
        fill(image, i, j - 1, color, newColor);
        fill(image, i, j + 1, color, newColor);
    }
    vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor)
            return image;
        fill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};