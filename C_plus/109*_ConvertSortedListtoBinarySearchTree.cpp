/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;

        int mid = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        // option 1 convert array and
        if (!head)
            return nullptr;
        if (!head->next)
            return new TreeNode(head->val);
        int len = 0;
        vector<int> v;
        ListNode *p = head;
        while (p)
        {
            len++;
            v.emplace_back(p->val);
            p = p->next;
        }
        return sortedArrayToBST(v);

        // option 2 slow-fast pointer
        if (!head)
            return nullptr;

        ListNode *fast = head, *slow = head, *pre = nullptr;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        if (pre != nullptr)
            pre->next = nullptr;
        else
            head = nullptr;

        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};