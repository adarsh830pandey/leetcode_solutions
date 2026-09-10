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
    // void inorderstore(TreeNode* root,vector<int>&inorder){
    //     if(root==NULL){
    //         return;
    //     }
    //     //LNR
    //     inorderstore(root->left,inorder);
    //     inorder.push_back(root->val);
    //     inorderstore(root->right,inorder);

    // }

    //dusra solution
    void solve(TreeNode*root,int k,int &count,int &ans){
        if(root==NULL){
            return;
        }
        //LNR
        //L
        solve(root->left,k,count,ans);
        //N
        count++;
        if(count==k){
            ans=root->val;
        }
        //R
        solve(root->right,k,count,ans);

    }


    int kthSmallest(TreeNode* root, int k) {
        // vector<int>inorder;
        // inorderstore(root,inorder);
        // return inorder[k-1];
        

        //dusra solution
        int count=0;
        int ans;
        solve(root,k,count,ans);
        return ans;
    }
};