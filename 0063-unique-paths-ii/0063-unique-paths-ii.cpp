class Solution {
public:
    
//     int minTotPaths(vector<vector<int>> &oG, int m,int n, vector<vector<int>> &dp){
        
//        // cout<<m<<" "<<n<<endl;
        
//         if(m < 0 || n < 0)
//             return 0;
        
//         if(oG[m][n] == 1)
//             return 0;
        
//         if(m==0 && n==0)
//             return 1;
        
//         if(dp[m][n]!=-1)
//             return dp[m][n];
        
//         return dp[m][n] = minTotPaths(oG,m-1,n,dp) + minTotPaths(oG,m,n-1,dp);
        
//     }
    
    int uniquePathsWithObstacles(vector<vector<int>>& oG) {
       
        
        
        int m = oG.size(), n = oG[0].size();
        
        if(m==1 && n==1)
            return !oG[0][0];
        
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        for(int i = 1; i<= m; i++){
            for(int j = 1; j<= n; j++){
                if(oG[i-1][j-1])
                    dp[i][j] = 0;
            }
        }
        
        if(!oG[0][0])
        dp[1][1] = 1;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j<= n; j++){
                if(i==1 && j==1)
                    continue;
                
                if(oG[i-1][j-1])
                    continue;
                
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m][n];
        
    }
};