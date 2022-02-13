#define max(a, b) ((a > b) ? a : b)
int costDays(int *weights, int weightsSize, int cap)
{

    int days = 0;
    for (int i = 0; i < weightsSize;)
    {

        int c = cap;
        while (i < weightsSize && c >= weights[i])
        {
            c -= weights[i];
            ++i;
        }
        days++;
    }

    return days;
}
int shipWithinDays(int *weights, int weightsSize, int days)
{
    int l = 0, r = INT_MAX;
    for (int i = 0; i < weightsSize; ++i)
    {
        l = max(l, weights[i]);
    }
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        int evalDay = costDays(weights, weightsSize, mid);
        if (evalDay == days)
            r = mid;
        else if (evalDay < days)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}