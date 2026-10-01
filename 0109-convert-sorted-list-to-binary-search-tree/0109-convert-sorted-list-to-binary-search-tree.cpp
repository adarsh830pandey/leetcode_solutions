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
class Solution {
public:
    int getsize(ListNode* head) {
        int count = 0;

        while (head != NULL) {
            count++;
            head = head->next;
        }

        return count;
    }

    TreeNode* buildtree(ListNode* head, int n) {

        if (head == NULL || n <= 0) {
            return NULL;
        }
       // middle find karo
        ListNode* temp = head;
        for (int i = 0; i < n / 2; i++) {
            temp = temp->next;
        }
       // middle ko root banao
        TreeNode* root = new TreeNode(temp->val);
         // left subtree
        root->left = buildtree(head, n / 2);
        // right subtree
        root->right = buildtree(temp->next, n - n / 2 - 1);
            return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = getsize(head);
        return buildtree(head, n);
    }
};