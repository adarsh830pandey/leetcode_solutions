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
//step 1->store inorder
    void inorderstore(TreeNode* root,vector<int>&inorder){
        if(root==NULL){
            return;
        }
        //LNR
        inorderstore(root->left,inorder);
        inorder.push_back(root->val);
        inorderstore(root->right,inorder);

    }
    //updating inorder
    void updateinorder(vector<int>&inorder){
        int n=inorder.size();
        for(int i=n-1; i>=0;i--){
            int curr=inorder[i];
            int next=0;
            if(i+1<n){
                next=inorder[i+1];
            }
            int sum=curr+next;
            inorder[i]=sum;
        }
    }

    void updatetree(TreeNode*&root,vector<int>&inorder,int &index){
        if(root==NULL){
            return;
        }
        //LNR
        updatetree(root->left,inorder,index);
        root->val=inorder[index];
        index++;
        updatetree(root->right,inorder,index);
    }




    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        if(root->left==NULL && root->right==NULL){
            return root;
        }
        vector<int>inorder;
        inorderstore(root,inorder);
        // step 2->update inorder
        
        updateinorder(inorder);
        //step->3 update the tree
        int index=0;
        updatetree( root,inorder,index);
        return root;
        
    }
};