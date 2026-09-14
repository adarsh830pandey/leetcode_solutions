class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        if (root == NULL) {
            return ans;
        }

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(to_string(root->val));
            return ans;
        }

        vector<string> leftans = binaryTreePaths(root->left);
        vector<string> rightans = binaryTreePaths(root->right);

        for (string path : leftans) {
            ans.push_back(to_string(root->val) + "->" + path);
        }

        for (string path : rightans) {
            ans.push_back(to_string(root->val) + "->" + path);
        }

        return ans;
    }
};