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
    
    bool isPair(TreeNode* root, unordered_set<int>& s, int k){
        if(root==NULL)
            return false;
        
        bool leftHas = isPair(root->left, s, k);
        if(leftHas)
            return true;
        if(s.find(k - root->val)!=s.end())
            return true;
        s.insert(root->val);
        return isPair(root->right, s, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return isPair(root, s, k);
    }
};