//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define long long ll



class Solution{
public:
    
    int dp[201][201][2];
 
    
    int count_ways(string s, int i, int j, int findTrue){
        
        if(i > j)
        return 0;
        
        if(i == j)
        {
            if(findTrue)
                return s[i] =='T';
            else 
                return s[i] =='F';
        }
        
        if(dp[i][j][findTrue] != -1)
            return dp[i][j][findTrue];
        
        int tot = 0, left_true, left_false, right_true, right_false;
        
        for(int k = i+1; k <= j-1; k+=2){
            
            
                left_true = count_ways(s, i,k-1,1);
                left_false = count_ways(s,i,k-1,0);
                right_true = count_ways(s,k+1,j,1);
                right_false = count_ways(s,k+1,j,0);
            
                if(s[k] == '|'){
                    
                    if(findTrue)
                    tot += (left_true)*(right_true) + (left_true)*(right_false) + (left_false)*(right_true);
                    else
                    tot += (left_false)*(right_false);
                    
                }
                else if(s[k] == '&'){
       
                    if(findTrue)
                    tot += (left_true)*(right_true);
                    else
                    tot += (left_false)*(right_false) + (left_true)*(right_false) + (left_false)*(right_true);
                  
                }
                else{
                
                    if(findTrue)
                    tot += (left_true)*(right_false) + (left_false)*(right_true);
                    else
                    tot += (left_true)*(right_true) + (left_false)*(right_false);
                 
                }
            
            
        }
        
        return dp[i][j][findTrue] = tot % 1003;
    }

    int countWays(int N, string S){
       
       int n = S.length();
       
       memset(dp, -1, sizeof(dp));
       
       return count_ways(S,0,n-1,1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends