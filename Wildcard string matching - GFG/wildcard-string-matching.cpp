//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
    bool canMatch(string w, string p, int i, int j, vector<vector<int>> &dp){
        
        if(j >= p.length() && i >= w.length())
        return true;
        
        if(j >= p.length() && i < w.length()){
            if(w[i] == '*')
            return canMatch(w,p,i+1,j,dp);
            return false;
        }
        
        
        
        if(i >= w.length() && j < p.length())
        return false;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(w[i]==p[j]){
            return dp[i][j] = canMatch(w,p,i+1,j+1, dp);
        }
        
        if(w[i] == '*'){
            bool op1 = canMatch(w,p,i,j+1, dp);
            bool op2 = canMatch(w,p,i+1,j,dp);
            
            return dp[i][j] = op1 | op2;
        }
        else if(w[i] == '?'){
            return canMatch(w,p,i+1,j+1,dp);
        }
        return dp[i][j] = false;
    }
    
    bool match(string wild, string pattern)
    {
        int n = wild.size(), m = pattern.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return canMatch(wild, pattern, 0, 0, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends