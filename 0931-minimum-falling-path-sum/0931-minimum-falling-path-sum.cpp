class Solution {
public:
    
    int getMaxFall(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &dp){
        
        
        if(j < 0 || j >= matrix[0].size())
            return 1e9;
        
        if(i == matrix.size()-1)
            return matrix[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = matrix[i][j] + min( getMaxFall(matrix, i+1,j+1,dp) , 
                                  min(getMaxFall(matrix, i+1,j,dp), getMaxFall(matrix, i+1,j-1,dp)) );
        
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m+2,1e9));
        
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = dp[i][m+1] = 1e9;
        }
        
        for(int j = 1; j <= m; j++){
            //cout<<matrix[n-1][j-1]<<endl;
            dp[n-1][j] = matrix[n-1][j-1];
        }
            
        
        int res = INT_MAX;
        
//         for(int i = 0; i < n ; i++){
//             for(int j = 0; j <= m+1; j++)
//                 cout<<dp[i][j]<<" ";
//             cout<<endl;
//         }
        
            
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