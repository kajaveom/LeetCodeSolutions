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
    
    int tiltSum(TreeNode* root, int &res){
        
        if(root == NULL)
            return 0;
        
        if(root -> left == NULL && root -> right == NULL)
            return root->val;
        
        int leftSum = tiltSum(root->left, res);
        int rightSum = tiltSum(root->right, res);
        
        res += abs(leftSum - rightSum);
        
        return leftSum + rightSum + root->val;
        
    }
    
    int findTilt(TreeNode* root) {
       
        int res = 0;
        tiltSum(root,res);
        return res;
    }
};