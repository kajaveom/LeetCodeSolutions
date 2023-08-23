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
    
    void delLeafTarget(TreeNode* &root, int t){
        if(root==NULL)
            return;
        
        delLeafTarget(root->left, t);
        delLeafTarget(root->right,t);
        
        if(root->left == NULL && root->right == NULL && root->val == t){
            root = NULL;
        }
        
        return;
    }
    
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        delLeafTarget(root,target);
        return root;
    }
};