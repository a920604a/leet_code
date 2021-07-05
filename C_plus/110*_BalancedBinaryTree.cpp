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
    int getHeight(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    int checkHeight(TreeNode *root)
    {
        if (root == nullptr)
            return -1;
        int leftHeight = checkHeight(root->left);
        if (leftHeight == INT_MIN)
            return INT_MIN; // Pass error up
        int rightHeight = checkHeight(root->right);
        if (rightHeight == INT_MIN)
            return INT_MIN; // Pass error up

        // What do we use for an error code? The height of a null tree is generally defined to be -1, so that's not a great idea for an error code. Instead, we' ll use Integer. MIN_VALUE.
        int heightDiff = leftHeight - rightHeight;
        if (heightDiff > 1)
            return INT_MIN;
        else
            return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        // option 1 O(N log N) time
        // 1. get left child tree hight and right child tree height
        // if(!root) return true;
        // int heightDiff = getHeight(root->left) - getHeight(root->right);
        // if(abs(heightDiff)>1 )return false;
        // else return isBalanced(root->left) && isBalanced(root->right);

        // option 2 O(N) time and O(Height) space
        return checkHeight(root) != INT_MIN;
    }
};

