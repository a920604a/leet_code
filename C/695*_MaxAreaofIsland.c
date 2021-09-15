
#define max(a, b) ((a > b) ? a : b)

void traverse(int **grid, int i, int j, int n, int m, int *ret)
{

    if (i < 0 || j < 0 || i > n - 1 || j > m - 1 || grid[i][j] == 0)
        return;
    grid[i][j] = 0;
    *ret += 1;
    traverse(grid, i - 1, j, n, m, ret);
    traverse(grid, i, j - 1, n, m, ret);
    traverse(grid, i + 1, j, n, m, ret);
    traverse(grid, i, j + 1, n, m, ret);
}
int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize)
{
    int ret = 0;
    for (int i = 0; i < gridSize; ++i)
    {
        for (int j = 0; j < *(gridColSize + i); j++)
        {
            if (grid[i][j] == 1)
            {
                int area = 0;
                traverse(grid, i, j, gridSize, *gridColSize, &area);
                ret = max(ret, area);
            }
        }
    }
    return ret;
}