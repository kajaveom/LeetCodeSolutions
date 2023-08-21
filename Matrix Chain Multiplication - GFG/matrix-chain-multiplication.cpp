//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dp[101][101];
    int getMin(int arr[], int i, int j){
        
        if(i==j)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int minSteps = INT_MAX;
        for(int k = i; k < j; k++){
            minSteps = min(minSteps, arr[i-1]*arr[k]*arr[j] + getMin(arr,i,k) + getMin(arr,k+1,j));
        }
        
        return dp[i][j] = minSteps;
    }

    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return getMin(arr,1,N-1);
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