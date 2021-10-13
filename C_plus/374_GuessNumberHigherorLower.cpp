/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        // time out
        // for(int i=n;i>=1;i--){
        //     if(guess(i)==0) return i;
        // }
        // return 1;

        // binary search
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int eval = guess(mid);
            if (eval == 0)
                return mid;
            else if (eval == -1)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};