class Solution {
public:
    
   
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m+2,1e9));
        
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = dp[i][m+1] = 1e9;
        }
        
        for(int j = 1; j <= m; j++){
            dp[n-1][j] = matrix[n-1][j-1];
        }
            
        
        int res = INT_MAX;
        
            
        for(int i = n-2; i >= 0; i--){
            for(int j = m; j >= 1; j--){
                
                dp[i][j] = matrix[i][j-1] + min( dp[i+1][j+1] ,  min(dp[i+1][j] , dp[i+1][j-1]) );
            }
        }
        
        for(int j = 1; j <= m; j++)
            res = min(res, dp[0][j]);
            
        
        
        return res;
        
        
    }
};