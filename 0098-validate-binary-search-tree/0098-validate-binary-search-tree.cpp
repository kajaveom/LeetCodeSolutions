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
    
    bool isBST(TreeNode* root, long long lb, long long ub){
        if(root==NULL)
            return true;
      
        
        if(root->val < ub && root->val > lb)
        {
            return (isBST(root->left, lb, root->val) && isBST(root->right, root->val, ub));
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        long long int lb = -100000000000, ub = 100000000000;
        return isBST(root,lb,ub);
    }
};