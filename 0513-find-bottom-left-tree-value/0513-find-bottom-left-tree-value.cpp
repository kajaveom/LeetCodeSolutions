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

    int leftBot =0, maxH = -1;

    void findLeftBottom(TreeNode* root,int h){
        if(root==NULL)
        return;

        if(h > maxH){
            leftBot = root->val;
            maxH = h;
        }

        findLeftBottom(root->left, h+1);
        findLeftBottom(root->right, h+1);

    }

    int findBottomLeftValue(TreeNode* root) {
        findLeftBottom(root,0);

        return leftBot;
    }
};