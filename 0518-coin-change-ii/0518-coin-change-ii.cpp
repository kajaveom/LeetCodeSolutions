class Solution {
public:
    
//     int totWays(vector<int> &c, int i, int a, vector<vector<int>> &dp){
        
//         if(a == 0)
//             return 1;
        
//         if(a < 0)
//             return 0;
        
//         if(i >= c.size())
//             return 0;
        
//         if(dp[i][a]!=-1)
//             return dp[i][a];
        
//         int w1 = totWays(c, i+1, a, dp);
//         int w2 = totWays(c, i, a - c[i], dp);
        
//         return dp[i][a] = w1 + w2;
//     }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
        for(int i = 0; i <= amount; i++)
            dp[n][i] = 0;
        for(int i = 0 ; i <= n; i++){
            dp[i][0] = 1;
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int a = 0; a <= amount ; a++){
                
                dp[i][a] = dp[i+1][a];
                if(a - coins[i] >= 0)
                    dp[i][a] += dp[i][a - coins[i]];
                
            }
        }
        
        return dp[0][amount];
    }
};