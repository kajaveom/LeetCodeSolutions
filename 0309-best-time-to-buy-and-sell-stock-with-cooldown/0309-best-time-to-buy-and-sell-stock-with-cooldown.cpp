class Solution {
public:
    
    int getMax(vector<int> &prices, int i, int buy, vector<vector<int>> &dp){
        
        if(i >= prices.size())
            return 0;
        
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        
        if(buy)
        {
            return dp[i][buy] = max( -prices[i] + getMax(prices,i+1,0,dp) , getMax(prices,i+1,1,dp));
        }
        
        return dp[i][buy] = max(prices[i] + getMax(prices,i+2,1,dp) , getMax(prices,i+1,0,dp));
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));
        
        for(int i = n-1; i >= 0; i--){
                dp[i][1] = max( -prices[i] + dp[i+1][0] , dp[i+1][1]);
                dp[i][0] = max( prices[i] + dp[i+2][1] ,dp[i+1][0] );  
            
        }
        
        
        return dp[0][1];
    }
};