//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

typedef struct TrieNode{
    
    TrieNode* arr[26];
    bool isEnd = false;
    
    TrieNode(){
        for(int i = 0; i < 26; i++){
            arr[i] = NULL;
        }
    }
    
}TrieNode;

class Solution{
public:


    void insert(TrieNode* &root, string s){
        
        int n = s.length();
        
        TrieNode *tN = root;
        for(int i = 0; i < n; i++){
            int indx = s[i] - 'a';
            
            if(tN->arr[indx]==NULL)
            {
                tN->arr[indx] = new TrieNode();
            }
            tN = tN->arr[indx];
        }
        
        tN->isEnd = true;
        return;
    }
    
    
    void getAllPref(TrieNode* &tN, vector<string>& tres, string s){
        
        if(tN->isEnd)
            tres.push_back(s);
        for(int i = 0; i < 26; i++){
            if(tN->arr[i]!=NULL){
                char tmp = 'a' + i;
                getAllPref(tN->arr[i], tres, s + tmp);
            }
        }
    }
    
    void solve(TrieNode* &tN, string s, vector<vector<string>> &res){
        
        TrieNode *tmp = tN;
        string pref = "";
        bool flag = false;
        for(int i = 0; i < s.length(); i++){
            int indx = s[i]-'a';
            vector<string> tres;
            
            if(flag)
            {
                res.push_back(vector<string>{"0"});
                continue;
            }
            
            if(tN->arr[indx]!=NULL){
                pref += s[i];
                getAllPref(tN->arr[indx], tres, pref);
                res.push_back(tres);
                
                tN = tN->arr[indx];
            }
            else
            {
                flag = true;
                res.push_back(vector<string>{"0"});
            }
        }
    }
    



    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < n; i++){
            insert(root,contact[i]);
        }
        
        vector<vector<string>> res;
        
        solve(root,s,res);
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends