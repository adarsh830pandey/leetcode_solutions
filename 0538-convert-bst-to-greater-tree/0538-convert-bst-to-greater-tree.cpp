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
    void storeinorder(TreeNode*root,vector<int>&inorder){
        if(root==NULL){
            return;
        }
        //LNR
        storeinorder(root->left,inorder);
        inorder.push_back(root->val);
        storeinorder(root->right,inorder);
    }
     void updateinorder(vector<int>& inorder) {
        int n = inorder.size();
        for (int i = n - 1; i >= 0; i--) {
            int curr = inorder[i];
            int next = 0;
            if (i + 1 < n) {
                next = inorder[i + 1];
            }
            int sum = curr + next;
            inorder[i] = sum;
        }
    }

    void updatetree(TreeNode*&root,vector <int> inorder,int &index){
        if(root==NULL){
            return;
        }
        //inorder waapas laga de
        //l
        updatetree(root->left,inorder,index);
        //n
        root->val=inorder[index];
        index++;
        //r
        updatetree(root->right,inorder,index);
    }
    TreeNode* convertBST(TreeNode* root) {
        //step 1->store inorder
        //we know inordr traversal gives sorted array
        vector <int> inorder;
        storeinorder(root,inorder);
        //step 2->find sum
        int n=inorder.size();
        updateinorder(inorder);
        //step 3->update the tree
        int index=0;
        updatetree(root,inorder,index);
        return root;


        
    }
};