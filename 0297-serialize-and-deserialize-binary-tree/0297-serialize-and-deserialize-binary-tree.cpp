/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    int index = 0;
    
    void getString(TreeNode* root, string& s){
        if(root==NULL)
        {
            s += "n ";
            return;
        }
        
        s += to_string(root->val);
        s += ' ';
        getString(root->left, s);
        getString(root->right, s);
        
        return;
        
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string s = "";
        getString(root, s);
        
       // cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        
        
        if(index >= data.length()-1)
            return NULL;
        
       // cout<<index<<" "<<data[index]<<endl;
        
        string tmp = "";
        while(index < data.length() && data[index]!=' '){
            tmp += data[index];
            index++;
        }
        index++;
        
        if(tmp=="n")
            return NULL;
        
        TreeNode *root = new TreeNode(stoi(tmp));
        root->left = deserialize(data);
        root->right = deserialize(data);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));