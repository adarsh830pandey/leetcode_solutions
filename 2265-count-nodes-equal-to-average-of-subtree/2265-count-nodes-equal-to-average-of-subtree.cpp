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
    pair<int, int> countvalues(TreeNode* root, int &count) {
        if (root == NULL) {
            return {0, 0};
        }

        pair<int, int> left = countvalues(root->left, count);
        pair<int, int> right = countvalues(root->right, count);

        int sum = left.first + right.first + root->val;
        int freq = left.second + right.second + 1;

        if (sum / freq == root->val) {
            count++;
        }

        return {sum, freq};
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;

        countvalues(root, count);

        return count;
    }
};