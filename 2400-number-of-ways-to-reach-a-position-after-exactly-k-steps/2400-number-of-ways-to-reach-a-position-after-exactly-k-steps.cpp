class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int tot_ways(int s, int k, int e, vector<vector<int>> &dp){
        
        if(k==0){
            if(s==e)
                return 1;
            return 0;
        }
        
        if(dp[s][k]!=-1)
            return dp[s][k];
        
        return dp[s][k] = ( tot_ways(s+1,k-1,e,dp) + tot_ways(s-1,k-1,e,dp) ) % mod;
    }
    
    
    int numberOfWays(int startPos, int endPos, int k) {
        
        
        int leftLimit = startPos - k;
        int rightLimit = startPos + k;
        
        if(leftLimit < 0){
            startPos += abs(leftLimit);
            endPos += abs(leftLimit);
        }
        else if(leftLimit > 0){
            startPos -= leftLimit;
            endPos -= leftLimit;
        }
        
        vector<vector<int>> dp(startPos + k + 1, vector<int>(k+1 , -1));
        
        return tot_ways(startPos, k, endPos, dp);
    }
};