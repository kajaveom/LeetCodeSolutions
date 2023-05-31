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
    
    
    TreeNode* prev = NULL;
    TreeNode* tmp1 = NULL;
    TreeNode* tmp2 = NULL;
    
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        
        inorder(root->left);
        if(prev == NULL)
            prev = root;
        else{
            if(prev->val > root->val){
                if(tmp1==NULL){
                    tmp1 = prev;
                    tmp2 = root;
                }
                else
                    tmp2 = root;
            }
            prev = root;
        }
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        
        int t = tmp1->val;
        tmp1->val = tmp2->val;
        tmp2->val = t;
    }
};
