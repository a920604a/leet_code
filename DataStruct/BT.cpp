
#include <vector>
#include <iostream>

class TreeNode
{
private:
    TreeNode *left;
    TreeNode *right;
    int val;

public:
    TreeNode() : left(nullptr), right(nullptr), val(0){};
    TreeNode(int x) : left(nullptr), right(nullptr), val(x){};

    friend class BinaryTree;
};

class BinaryTree
{
private:
    TreeNode *root;

public:
    BinaryTree() : root(nullptr){};

    void LevelorderConstruct(vector<int> &vec);
    void InsertLevelorder(int x);

    TreeNode *leftmost(TreeNode *root);
    TreeNode *InorderSuccessor(TreeNode *root);
    void Inorder_by_parent();
}