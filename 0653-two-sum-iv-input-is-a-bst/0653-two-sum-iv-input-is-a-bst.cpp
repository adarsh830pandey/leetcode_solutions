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
    void inorderstore(TreeNode* root,vector<int>&inorder){
        if(root==NULL){
            return;
        }
        //LNR
        inorderstore(root->left,inorder);
        inorder.push_back(root->val);
        inorderstore(root->right,inorder);

    }
    bool checksum(vector <int> inorder,int k){
        int s=0;
        int e=inorder.size()-1;
        while(s<e){
            if(inorder[s]+inorder[e]==k){
                return true;
            }
            if(inorder[s]+inorder[e]>k){
                e--;
            }
            if(inorder[s]+inorder[e]<k){
                s++;
            }
        }
        return false;
    }




     bool findTarget(TreeNode* root, int k) {
        //logic y hai kin inorder traversal karake store karakew two pointer approach laga denge
        vector<int>inorder;
        inorderstore(root,inorder);
        bool ans=checksum(inorder,k);
        return ans;
        
    }
};