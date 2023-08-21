//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dp[101][101];


    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,0,sizeof(dp));
        
        for(int i = N-1; i >= 1; i--){
            for(int j = 1; j < N; j++){
                
                if(i==j){
                    continue;
                }
                
                int minSteps = INT_MAX;
                for(int k = i; k < j; k++){
                    minSteps = min(minSteps, arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j] );
                }
                
                dp[i][j] = minSteps;
            }
        }
        
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends