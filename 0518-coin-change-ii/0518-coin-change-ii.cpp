class Solution {
public:
    
    int totWays(vector<int> &c, int i, int a, vector<vector<int>> &dp){
        
        if(a == 0)
            return 1;
        
        if(a < 0)
            return 0;
        
        if(i >= c.size())
            return 0;
        
        if(dp[i][a]!=-1)
            return dp[i][a];
        
        int w1 = totWays(c, i+1, a, dp);
        int w2 = totWays(c, i, a - c[i], dp);
        
        return dp[i][a] = w1 + w2;
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        
        return totWays(coins,0,amount, dp);
    }
};