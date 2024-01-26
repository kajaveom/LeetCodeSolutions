class Solution {
public:
    
    const int mod = 1e9+7;
    
    int totPaths(int sR, int sC, int m, int n, int mM, vector<vector<vector<int>>> &dp){
        
        if(sR < 0 || sC < 0 || sR >= m || sC >= n){
            return 1;
        }
        
        if(mM<=0)
            return 0;
        
        if(dp[sR][sC][mM]!=-1)
            return dp[sR][sC][mM];
           
        //case1
        int left = totPaths(sR, sC-1, m, n, mM-1,dp);
        
        //case2
        int right = totPaths(sR, sC+1, m, n, mM-1,dp);
        
        //case3
        int up = totPaths(sR-1,sC, m, n, mM-1,dp);
        
        //case4
        int down = totPaths(sR+1,sC, m, n, mM-1,dp);
    
        return dp[sR][sC][mM] = ((((left + right)%mod) + up)%mod + down)%mod;
        
        
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(
                n, vector<int>(maxMove+1, -1)
            )
        );
        
        return totPaths(startRow, startColumn, m, n, maxMove, dp);
        
    }
};