

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void fill(int **image, int imageSize, int imageColSize, int i, int j, int newColor, int oldColor)
{

    if (i < 0 || i > imageSize - 1 || j < 0 || j > imageColSize - 1 || image[i][j] != oldColor)
        return;

    image[i][j] = newColor;
    fill(image, imageSize, imageColSize, i - 1, j, newColor, oldColor);
    fill(image, imageSize, imageColSize, i, j - 1, newColor, oldColor);
    fill(image, imageSize, imageColSize, i, j + 1, newColor, oldColor);
    fill(image, imageSize, imageColSize, i + 1, j, newColor, oldColor);
}
int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int newColor, int *returnSize, int **returnColumnSizes)
{
    //  1   1   1
    //  1   1   0
    //  1   0   1

    *returnSize = imageSize;
    int oldColor = image[sr][sc];
    *returnColumnSizes = malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; ++i)
    {
        (*returnColumnSizes)[i] = imageColSize[i];
    }
    if (image[sr][sc] == newColor)
        return image;

    fill(image, imageSize, *imageColSize, sr, sc, newColor, oldColor);
    return image;
}