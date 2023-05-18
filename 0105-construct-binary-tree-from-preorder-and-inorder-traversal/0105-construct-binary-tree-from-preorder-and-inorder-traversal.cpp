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
    
    int preIndex = 0;
    
    TreeNode* constructTree(vector<int> preorder, vector<int> inorder, int si, int ei){
        
        if(si > ei)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        
        int inIndex = 0;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i]==root->val){
                inIndex = i;
                break;
            }
        }
        
        root->left = constructTree(preorder,inorder,si,inIndex-1);
        root->right = constructTree(preorder,inorder,inIndex+1,ei);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return constructTree(preorder, inorder, 0, inorder.size()-1);
    }
};