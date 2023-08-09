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
        vector<int> ahead(2,0); 
        
        for(int i = n-1; i >= 0; i--){
        
            for(int b = 0; b < 2; b++){
                if(b)
                ahead[b] = max( -prices[i] + ahead[0] , ahead[1] );
                else
                ahead[b] = max( prices[i] + ahead[1], ahead[0])  ;
            }
        }
        
        
        
        return ahead[1];
        
    }
};