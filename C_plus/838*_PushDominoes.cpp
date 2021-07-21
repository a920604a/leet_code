class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        // https://www.cnblogs.com/grandyang/p/10393508.html
        // 分為四種情況
        // 情況一 R...R => RRRRR ， 骨牌往右倒
        // 情況二 L...L => LLLLL ， 骨牌往左倒
        // 情況三 L...R => L...R ， 中間骨牌不受力
        // 情況四 R...L => RRRLLL or RRR.LLL ， 要看中間骨牌個數，如果是偶數，那對半，若是奇數，那最中間股台保持站立，其餘對半分

        // 所以只要者出最中間的“.”的小區間，使用雙指針遍歷。
        string res = "";
        // j指向“.” 則跳過，目標是i指向小區間的左邊界，j指向右邊界，j-i-1則是中間"點"的個數。
        // 若 i > 0<
        dominoes = "L" + dominoes + "R";
        for (int i = 0, j = 1; j < dominoes.size(); ++j)
        {
            if (dominoes[j] == '.')
                continue;
            int mid = j - i - 1;
            // 情況二
            if (i > 0)
                res += dominoes[i];
            // 情況一
            if (dominoes[i] == dominoes[j])
                res += string(mid, dominoes[i]);
            // 情況三
            else if (dominoes[i] == 'L' && dominoes[j] == 'R')
                res += string(mid, '.');
            // 情況四
            else
                res += string(mid / 2, 'R') + string(mid % 2, '.') + string(mid / 2, 'L');
            i = j;
            cout << res << endl;
        }
        return res;
    }
};