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
	
	
	ll countStrings(int n) {
	    // code here
	    
	    vector<vector<int>> dp(n+1,vector<int>(2,0));
	    dp[0][0] = 1;
	    dp[0][1] = 1;
	    
	    for(int i = 1; i <= n; i++){
	        for(int s = 0; s < 2; s++){
	            ll cnt = 0;
        	    if(!s)
        	    cnt += dp[i-1][1];
        	    cnt += dp[i-1][0];
        	    
        	    dp[i][s] = cnt % mod;
	        }
	    }

	    
	    return dp[n][0]%mod;

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