class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
            
        
        int n = prices.size();
        vector<int> aft1(2,0);
        vector<int> cur(2,0);
        
        for(int i = n-1; i >= 0; i--){
               cur[1] = max( -prices[i] + aft1[0] , aft1[1]);
               cur[0] = max( prices[i] - fee + aft1[1] ,aft1[0] );  
            
            aft1 = cur;
        }
        
    
        return cur[1];
    }
};