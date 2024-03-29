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
    unordered_map<int,int> indexes;
    
    TreeNode* constructTree(vector<int> preorder, vector<int> inorder, int si, int ei){
        
        if(si > ei)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        
        int inIndex = indexes[root->val];
        
        root->left = constructTree(preorder,inorder,si,inIndex-1);
        root->right = constructTree(preorder,inorder,inIndex+1,ei);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        for(int i = 0; i < inorder.size(); i++){
            indexes[inorder[i]] = i;
        }
        
        return constructTree(preorder, inorder, 0, inorder.size()-1);
    }
};