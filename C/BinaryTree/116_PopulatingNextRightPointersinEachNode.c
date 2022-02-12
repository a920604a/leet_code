/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void connection(struct Node *left, struct Node *right)
{

    if (!left || !right)
        return;

    left->next = right;
    connection(left->left, left->right);
    connection(right->left, right->right);
    connection(left->right, right->left);
}
struct Node *connect(struct Node *root)
{
    if (!root)
        return root;
    connection(root->left, root->right);
    return root;
}