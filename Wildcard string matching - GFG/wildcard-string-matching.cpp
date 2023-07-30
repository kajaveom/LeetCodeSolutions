//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
    
    bool match(string w, string p)
    {
        int n = w.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
        
        dp[n][m] = true;
        for(int i = n-1; i >= 0; i--){
            if(w[i]=='*')
            dp[i][m] = dp[i+1][m];
            else
            dp[i][m] = false;
        }
        
        for(int j = m-1; j >= 0; j--){
            dp[n][j] = false;
        }
        
        
        for(int i = n-1; i >= 0 ; i--){
            for(int j = m-1; j >= 0; j--){
                
                if(w[i]==p[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(w[i] == '*'){
                    bool op1 = dp[i][j+1];
                    bool op2 = dp[i+1][j];
                    
                    //cout<<i<<" "<<j<<" "<<op1<<" "<<op2<<endl;
                    
                    dp[i][j] = (op1 | op2);
                }
                else if(w[i] == '?'){
                    dp[i][j] = dp[i+1][j+1];
                }
                else
                dp[i][j] = 0;
                
            }
        }
        
        
        // for(int i = 0; i <= n; i++){
        //     for(int j = 0; j <= m; j++)
        //     cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        
        
        
        return  dp[0][0];
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