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
        
        int n = triangle.size(), m = triangle.size();
        vector<vector<int>> dp(n, vector<int>(m ,-1));
        return getMinPath(triangle,0,0,dp);
        
    }
};