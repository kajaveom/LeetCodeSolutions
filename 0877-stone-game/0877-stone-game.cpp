class Solution {
public:
    
    int getMax(vector<int>& p, int i, int j, vector<vector<int>> &dp){
        
        if(i == j){
            return p[i];
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        //case1 
        int leftPick = -getMax(p,i+1,j, dp) + p[i];
        
        //case 2
        int rightPick = -getMax(p,i,j-1, dp) + p[j];
        
        return dp[i][j] = max(leftPick, rightPick);
        
        
    }
    
    bool stoneGame(vector<int>& piles) {
     
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        
        if(getMax(piles,0,n-1,dp) < 0)
            return false;
        
        return true;
    }
};