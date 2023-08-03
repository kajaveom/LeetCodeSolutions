class Solution {
public:
    
    int minSum(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        
        if(i >= grid.size() || j >= grid[0].size())
            return INT_MAX - 500;
        
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return grid[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int w1 = grid[i][j] + minSum(grid, i+1,j, dp);
        int w2 = grid[i][j] + minSum(grid,i,j+1, dp);
        
        return dp[i][j] = min(w1,w2);
    }
    
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,1e9));
        
        dp[m-1][n-1] = grid[m-1][n-1];
        
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i==m-1 && j==n-1)
                    continue;
                dp[i][j] = grid[i][j] + min( dp[i+1][j],  dp[i][j+1] );
            }
        }
        
        return dp[0][0];
    }
};