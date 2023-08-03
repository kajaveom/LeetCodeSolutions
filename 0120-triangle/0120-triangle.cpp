class Solution {
public:
    
    int getMinPath(vector<vector<int>> &t, int i, int j, vector<vector<int>> &dp){
        
        if(i == t.size()-1)
            return t[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = t[i][j]  + min( getMinPath(t,i+1,j, dp)  ,  getMinPath(t,i+1,j+1, dp) );
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n ,-1));
        
        for(int j = 0; j < n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        
        for(int i=n-2; i >= 0; i--){
            for(int j = i; j >= 0; j--)
            dp[i][j] = triangle[i][j]  + min( dp[i+1][j] , dp[i+1][j+1] );
            
        }
        
        return dp[0][0];
        
    }
};