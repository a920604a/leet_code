class Solution
{
public:
    bool NumberTraverse(vector<int> &nums, int index, vector<int> &bucket, int target)
    {

        if (index == nums.size())
        {
            // 檢查每個桶數字之和是否都是 target
            for (int b : bucket)
            {
                if (b != target)
                    return false;
            }
            return true;
        }

        // for(int i = ; i<nums.size() ;++i){
        //     // 窮舉每個桶
        //     for(int j=0;i<bucket.size() ; ++j){
        //         // nums[i]  選擇是否要進入第 j 個桶子
        //     }
        // }
        // k 個桶子，紀錄每個桶裝的數字之和

        // 改成遞回方式
        // 窮舉每個桶
        for (int i = 0; i < bucket.size(); ++i)
        {

            if (bucket[i] + nums[index] > target)
                continue;
            // 選擇裝進 第 i 個桶子
            bucket[i] += nums[index];

            // 遞回窮舉下一個數字的選擇
            if (NumberTraverse(nums, index + 1, bucket, target))
                return true;
            // 撤銷選擇
            bucket[i] -= nums[index];
        }
        // nums[index] 裝到哪個桶都不行
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {

        int target = 0;
        for (int n : nums)
            target += n;
        if (target % k != 0)
            return false;
        target /= k;

        // option 1 以 這 n 個數字的視角，每個數字都要選則進入 k 個桶的某一個
        // 原始版本會 Time Limit Exceeded
        // 事先排序降序，並在NumberTraverse 遍歷時加入判斷
        // sort(nums.begin(), nums.end(),greater<int>() ); //或 sort(nums.rbegin(),nums.rend());
        // vector<int> bucket(k);

        // return NumberTraverse(nums, 0, bucket, target);

        // option 2 以 這 k 個桶子的視角，對於每個桶都要遍歷nums 中的 n 個數字，然後選擇是否將當前遍歷的數字裝到自己這個桶子里
        // 從第 k 個桶開始
        vector<bool> used(nums.size(), false);
        cout << target << endl;
        return BucketTraverse(nums, k, 0, used, 0, target);
    }
    bool BucketTraverse(vector<int> &nums, int k, int bucketSum, vector<bool> &used, int start, int target)
    {
        // base case
        if (k == 0)
        {
            // 所有桶都被裝滿，而且 nums 一定都用完了
            // 因為 target == sum /k
            return true;
        }
        if (bucketSum == target)
        {
            // 當前的桶子 k 裝滿了，需要換下一個桶子
            return BucketTraverse(nums, k - 1, 0, used, 0, target);
        }
        //  改成遞回方式
        for (int i = start; i < nums.size(); ++i)
        {
            // 剪枝，拜訪 沒拜訪過的
            if (used[i] == false)
            {
                // 該桶子裝不下 nums[i]
                if (bucketSum + nums[i] > target)
                    continue;

                // 選擇裝進 第 i 個數字 到 第 k 個桶
                used[i] = true;
                bucketSum += nums[i];
                if (BucketTraverse(nums, k, bucketSum, used, i + 1, target))
                    return true;
                // 撤銷選擇
                used[i] = false;
                bucketSum -= nums[i];
            }
        }
        return false;

        //         // 直到所有桶都裝滿
        //         while(k > 0){
        //             // 紀錄當前桶數字之和
        //             int bucketSum = 0;
        //             for(int i=0;i<nums.size() ;++i){
        //                 // 決定是否將 nums[i] 放入當前桶中
        //                 bucketSum += nums[i];
        //                 if(bucketSum == target ){
        //                     // 裝滿了一個桶，妝下一個桶
        //                     k--;
        //                     break;
        //                 }

        //             }
    }
};