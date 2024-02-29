class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        TreeNode* temp=root;
        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty())
        {
            int l=q.size();  
            TreeNode* f=q.front();
            q.pop();
			
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
            int v=f->val;
			
            if(cnt%2==0 && !(v&1)) 
                return false;
            if(cnt&1 && (v&1)) 
                return false;
            for(int i=0;i<l-1;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(cnt%2==0)                   
                {
                    if(curr->val <= v || !((curr->val)&1)) 
                        return false;
                    v=curr->val;
                }
                else                           
                {
                    if(curr->val >= v || (curr->val)&1) 
                        return false;
                    v=curr->val;
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            cnt++;
        }
        return true;
    }
};
