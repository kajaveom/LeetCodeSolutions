class Solution {
public:
    
    int dp[1001][101][2];
    int getMaxP(vector<int>& p, int i, int b, int k){
        
        if(i == p.size())
            return 0;
        
        if(k <= 0)
            return 0;
        
        if(dp[i][k][b]!=-1)
            return dp[i][k][b];
        
        if(b){
            return dp[i][k][b] = max( -p[i] + getMaxP(p,i+1,0,k) , getMaxP(p,i+1,1,k));
        }
        
        return dp[i][k][b] = max( p[i] + getMaxP(p,i+1,1,k-1) , getMaxP(p,i+1,0,k));
        
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1,sizeof(dp));
        return getMaxP(prices,0,1,k);
    }
};