class Solution {
public:
    
//     int getMax(vector<int> &prices, int i, int buy, vector<vector<int>> &dp){
        
//         if(i >= prices.size())
//             return 0;
        
//         if(dp[i][buy]!=-1)
//             return dp[i][buy];
        
//         if(buy)
//         {
//             return dp[i][buy] = max( -prices[i] + getMax(prices,i+1,0,dp) , getMax(prices,i+1,1,dp));
//         }
        
//         return dp[i][buy] = max(prices[i] + getMax(prices,i+2,1,dp) , getMax(prices,i+1,0,dp));
//     }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> aft2(2,0);
        vector<int> aft1(2,0);
        vector<int> cur(2,0);
        
        for(int i = n-1; i >= 0; i--){
               cur[1] = max( -prices[i] + aft1[0] , aft1[1]);
                cur[0] = max( prices[i] + aft2[1] ,aft1[0] );  
            
            aft2 = aft1;
            aft1 = cur;
        }
        
    
        return cur[1];
    }
};