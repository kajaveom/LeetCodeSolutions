//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	
	const int mod = 1e9+7;
	
	ll solve(int n, int set, vector<vector<int>> &dp){
	    
	    if(n==0)
	    return 1;
	    
	    
	    if(dp[n][set]!=-1)
	    return dp[n][set];
	    
	    ll cnt = 0;
	    if(!set)
	    cnt += solve(n-1,1,dp);
	    cnt += solve(n-1,0,dp);
	    
	    return dp[n][set] = cnt % mod;
	}
	
	
	ll countStrings(int n) {
	    // code here
	    
	    vector<vector<int>> dp(n+1,vector<int>(2,-1));
	    
	    return solve(n,0,dp);

	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends