/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int countPathsWithSumFromNode(TreeNode *node, int targetSum, int currentSum)
    {
        if (!node)
            return 0;

        currentSum += node->val;
        int totalPaths = 0;
        if (currentSum == targetSum)
        { // Found a path from the root
            totalPaths++;
        }

        totalPaths += countPathsWithSumFromNode(node->left, targetSum, currentSum);
        totalPaths += countPathsWithSumFromNode(node->right, targetSum, currentSum);
        return totalPaths;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        // option1 DFS O(N log N) times
        if (!root)
            return 0;

        /* Count paths with sum starting from the root. */
        int pathsFromRoot = countPathsWithSumFromNode(root, targetSum, 0);

        /* Try the nodes on the left and right. */
        int pathsOnLeft = pathSum(root->left, targetSum);
        int pathsOnRight = pathSum(root->right, targetSum);
        return pathsFromRoot + pathsOnLeft + pathsOnRight;


        // option 2 DFS + hash table O(N) or O(logN) for balanced tree
        unordered_map<int, int> pathCount;
        pathCount[0] = 1;
        int ret = countPathWitheSum(root, targetSum, 0, pathCount);

        return ret;
    }

    int countPathWitheSum(TreeNode *root, int targetSum, int curSum, unordered_map<int, int> &pathCount)
    {
        if (!root)
            return 0; // Base case

        /* Count paths with sum ending at the the current node */
        curSum += root->val;
        int sum = curSum - targetSum;
        int totalPaths = 0;

        /*  If curSum eaquls targetSum , then one additionl path starts at root. 
        Add in this path */
        if (pathCount.count(sum))
            totalPaths = pathCount[sum];

        /*  Increment pathCount, recurse, then decrement pathCount. */

        pathCount[curSum]++; // incrementHashTable(pathCount, curSum, 1);

        totalPaths += countPathWitheSum(root->left, targetSum, curSum, pathCount);
        totalPaths += countPathWitheSum(root->right, targetSum, curSum, pathCount);

        pathCount[curSum]--; // incrementHashTable(pathCount, curSum, -1);
        return totalPaths;
    }
    void incrementHashTable(unordered_map<int, int> &pathCount, int key, int delta)
    {
        int newCount = pathCount.count(key) ? pathCount[key] : 0;
        newCount += delta;
        if (newCount == 0)
            pathCount.erase(key);
        else
            pathCount[key] = newCount;
    }
};