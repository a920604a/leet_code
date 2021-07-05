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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        else if (!p || !q)
            return false;
        else if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false; // p->val !=q->val
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        // option 1
        // if (!root) return false;
        // if (isSameTree(root, subRoot)) return true;
        // return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

        // option 1.1 is equal to option 1
        // O(n + m)  time and O(log(n) + log(m)) space
        //         if(subRoot==nullptr) return true;
        //         if(root==nullptr) return false;
        //         else if(root->val ==subRoot->val && isSameTree(root, subRoot)) return true;
        //         return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

        // option 2
        // 將每個葉子的left child 補上 "#"
        string str1, str2;
        serialize(root, str1);
        serialize(subRoot, str2);
        cout << str1 << endl
             << str2 << endl;
        return str1.find(str2) != string::npos;
    }
    void serialize(TreeNode *node, string &str)
    {
        if (node == nullptr)
        {
            str.append("X");
            return;
        }
        //in-order traverse
        str.append("," + to_string(node->val)); //avoid [12] [2]
        serialize(node->left, str);
        serialize(node->right, str);
    }
};