class Solution
{
public:
    void flood(int i, int j, int color, int newColor, vector<vector<int> > &ret)
    {
        if (i < 0 || j < 0 || i > ret.size() - 1 || j > ret[0].size() - 1 || ret[i][j] != color)
            return;
        ret[i][j] = newColor;

        flood(i - 1, j, color, newColor, ret);

        flood(i + 1, j, color, newColor, ret);
        flood(i, j - 1, color, newColor, ret);
        flood(i, j + 1, color, newColor, ret);
    }
    vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc, int newColor)
    {

        // option 1 DFS
        if (image[sr][sc] == newColor)
            return image;
        int m = image.size(), n = image[0].size();
        vector<vector<int> > ret = image;

        flood(sr, sc, image[sr][sc], newColor, ret);

        return ret;
    }
};