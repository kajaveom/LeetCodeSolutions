class Solution {
public:
    
    int minTotPaths(vector<vector<int>> &oG, int m,int n, vector<vector<int>> &dp){
        
       // cout<<m<<" "<<n<<endl;
        
        if(m < 0 || n < 0)
            return 0;
        
        if(oG[m][n] == 1)
            return 0;
        
        if(m==0 && n==0)
            return 1;
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        return dp[m][n] = minTotPaths(oG,m-1,n,dp) + minTotPaths(oG,m,n-1,dp);
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& oG) {
       
        int m = oG.size(), n = oG[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return minTotPaths(oG,m-1,n-1,dp);
        
    }
};