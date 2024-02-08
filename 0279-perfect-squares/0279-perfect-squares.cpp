class Solution {
public:
    

    int numSquares(int n) {
        
        vector<int> dp(n + 1, 0);
        
        for(int n1 = 1; n1 <= n; n1++){
            
            int i= 1, mini = INT_MAX;
            while(true){
                if( n1 - (i*i) < 0){
                    break;
                }

                mini = min(mini , dp[n1 - (i*i)] + 1);
                i++;
            }
            
            dp[n1] = mini;
        }
        
        
        return dp[n];
        
    }
};