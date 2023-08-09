class Solution {
public:
    
//     int maxP(vector<int> &prices, int i, int b, vector<vector<int>>&dp){
        
//         if(i == prices.size())
//             return 0;
        
//         if(dp[i][b]!=-1)
//             return dp[i][b];
        
//         if(b){
//             return dp[i][b] = max( -prices[i] + maxP(prices,i+1,0,dp) , maxP(prices,i+1,1,dp));
//         }
        
//         return dp[i][b] = max(prices[i] + maxP(prices,i+1,1,dp) , maxP(prices,i+1,0,dp));
        
//     }
    
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        for(int i = n-1; i >= 0; i--){
        
            for(int b = 0; b < 2; b++){
                if(b)
                dp[i][b] = max( -prices[i] + dp[i+1][0] , dp[i+1][1] );
                else
                dp[i][b] = max( prices[i] + dp[i+1][1], dp[i+1][0])  ;
            }
        }
        
        
        
        return dp[0][1];
        
    }
};