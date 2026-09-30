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
    void givesum(TreeNode* root,int &sum,bool isleft){
        //base case
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            if(isleft){
                 sum+=root->val;
                 return;

            }
           
        }
        givesum(root->left,sum,true);
        givesum(root->right,sum,false);
        

        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        givesum(root,sum,false);
        return sum;
    }
      
};