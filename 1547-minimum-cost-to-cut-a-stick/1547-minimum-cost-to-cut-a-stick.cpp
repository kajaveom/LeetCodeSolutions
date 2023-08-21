class Solution {
public:
    
    int dp[103][103];
   
    
    int minCost(int n, vector<int>& cuts) {
        
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int len = cuts.size();

        memset(dp, 0, sizeof(dp));
        
        for(int i = len-2; i >= 1; i--){
            for(int j = i; j <= len-2; j++){
                
                int mini = INT_MAX;
                for(int k = i; k <= j; k++){
                    mini = min( mini, cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j] ) ;
                }

                dp[i][j] = mini;
                
                
            }
        }  
        return dp[1][len-2];
    }
};