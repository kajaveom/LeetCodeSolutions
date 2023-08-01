class Solution {
public:
    
    int rec(int f, int e, vector<vector<int>> &dp){
        
        if(f==0)
            return 0;
        if(f==1)
            return 1;
        if(e==1)
            return f;
        if(e==0)
            return 0;
        //cout<<f<<" "<<e<<endl;
        
        if(dp[f][e]!=-1)
            return dp[f][e];
        
        int min_try = INT_MAX;
        for(int i = 1; i <= f; i++){
            min_try = min(min_try ,  max( rec(i-1,e-1,dp) , rec(f-i, e, dp) ) );
        }
        
        return dp[f][e] = min_try + 1;
        
    }
    
    int superEggDrop(int k, int n) {
        
        vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
        
        for(int i = 0; i <= k; i++)
        {
            dp[0][i] = 0;
            dp[1][i] = 1;
        }
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
            dp[i][1] = i;
        }
        
        dp[0][1] = 0;
        dp[1][1] = 1;
        
        for(int i = 2; i <= n; i++){
            for(int j = 2; j <= k; j++){

                int min_try = INT_MAX;
                int low = 0;
                int high = i;
                while(low <= high){
                    int mid = (low+high)/2;
                    
                    int left = dp[mid-1][j-1];
                    int right = dp[i-mid][j];
                    
                    min_try = min(min_try, 1 + max(left, right));
                    
                    if(left > right){
                        high = mid-1;
                    }    
                    else{
                        low = mid + 1;
                    }
                }
                
                 dp[i][j] = min_try;
            }
        }
        
        return dp[n][k];
        
    }
};