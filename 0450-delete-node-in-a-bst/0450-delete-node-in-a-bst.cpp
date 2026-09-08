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
    int getmax(TreeNode*root){
    if(root==NULL){
        return -1;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    //jab mai yha aaya iska matlab root ka right NULL hai aur root ka data max value hai
    return root->val;
}



    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            //matching case
            //1->leaf node
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            // 2->only left element
            if(root->left!=NULL && root->right==NULL){
                TreeNode*leftchild=root->left;
                root->left=NULL;//kind of separating child root connectoion
                delete root;
                return leftchild;
            }
            // 3->only right element
            if(root->left==NULL && root->right!=NULL){
                TreeNode*rightchild=root->right;
                root->right=NULL;//kind of separating child root connectoion
                delete root;
                return rightchild;
            }
            // 4->both left and right hai
            if(root->left!=NULL && root->right!=NULL){
                int max=getmax(root->left);
                root->val=max;
                //ab us copied element ko delete bhi karrni hai
                root->left=deleteNode(root->left,max);
            }
        }
        else{
            //non-matching case me search karrna hai
            if(key<root->val){
                root->left=deleteNode(root->left,key);
            }
            else{
                root->right=deleteNode(root->right,key);
            }
        }
        return root;
    }
};