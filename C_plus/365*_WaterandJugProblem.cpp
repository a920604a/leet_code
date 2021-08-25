class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
    {

        if (targetCapacity == 0)
            return true;
        if (jug1Capacity + jug2Capacity >= targetCapacity && targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0)
            return true;
        return false;
    }
};