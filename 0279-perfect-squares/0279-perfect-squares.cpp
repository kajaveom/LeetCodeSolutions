class Solution {
public:
    
    int getLeastNumbers(int n, vector<int>& dp){
        
       // cout<<n<<endl;
        
        if(n <= 0)
            return 0; 
        
        if(dp[n]!=-1)
            return dp[n];
        
        int i= 1, mini = INT_MAX;
        while(true){
            if( n - (i*i) < 0){
                break;
            }
            
            mini = min(mini , getLeastNumbers(n - (i*i), dp) + 1);
            i++;
        }
        
        return dp[n] = mini;
        
    }
    
    int numSquares(int n) {
        
        vector<int> dp(n + 1, -1);
        
        
        
        
        return getLeastNumbers(n, dp);
        
    }
};