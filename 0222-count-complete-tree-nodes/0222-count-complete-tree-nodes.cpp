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
    
    int getHeight(TreeNode* root, int dir){
        if(root==NULL)
            return 0;
        
        if(dir == 0)
            return getHeight(root->left, dir) + 1;
        
        return getHeight(root->right, dir) + 1;
    } 
    
    int getCount(TreeNode* root, int lH, int rH){
        if(root==NULL)
            return 0;
        
        if(lH == -1)
        {
            lH = getHeight(root->left,0);
        }
        
        if(rH == -1){
            rH = getHeight(root->right,1);
        }
       
        if(lH == rH && lH!=0){
            //cout<<root->val<<" "<<lH<<endl;
            return pow(2 , lH+1) -1;
        }
        
        return getCount(root->left, lH-1, -1) + getCount(root->right, -1, rH-1) + 1;
    }

    int countNodes(TreeNode* root) {
       return getCount(root,-1,-1);
    }
};