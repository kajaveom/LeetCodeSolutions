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
    
    int maxDiameter = INT_MIN;
    
    int getDiameter(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        int lH = getDiameter(root->left);
        int rH = getDiameter(root->right);
        
        maxDiameter = max( maxDiameter, lH+rH);
        
        return max(lH,rH) + 1;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        getDiameter(root);
        return maxDiameter;
    }
};