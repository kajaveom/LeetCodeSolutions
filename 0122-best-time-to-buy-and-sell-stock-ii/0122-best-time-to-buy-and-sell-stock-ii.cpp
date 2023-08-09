class Solution {
public:
    
    int maxP(vector<int> &prices, int i, int b, vector<vector<int>>&dp){
        
        if(i == prices.size())
            return 0;
        
        if(dp[i][b]!=-1)
            return dp[i][b];
        
        if(b){
            return dp[i][b] = max( -prices[i] + maxP(prices,i+1,0,dp) , maxP(prices,i+1,1,dp));
        }
        
        return dp[i][b] = max(prices[i] + maxP(prices,i+1,1,dp) , maxP(prices,i+1,0,dp));
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return maxP(prices,0,1,dp);
        
    }
};