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
    
    int totPalinPaths(TreeNode* root, int bitMap){
        
        if(root==NULL)
            return 0;
        
        int setBit = (1 << (root->val));
        bitMap ^= setBit;
        
        int left = totPalinPaths(root->left,bitMap);
        int right = totPalinPaths(root->right, bitMap);
        
        if(root->left == NULL && root->right== NULL)
        {
            if(!bitMap || !(bitMap&(bitMap-1))){
                return 1;
            }
            
            return 0;
        }
        
        return left+right;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int bitMap = 0;
        return totPalinPaths(root,bitMap);
        
    }
};