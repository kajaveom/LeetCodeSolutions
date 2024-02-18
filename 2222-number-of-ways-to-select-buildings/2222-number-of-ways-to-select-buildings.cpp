class Solution {
public:
    long long numberOfWays(string s) {
        
        
        long long ones = 0, zeros = 0, res = 0;
        vector<vector<long long>> dp(2, vector<long long>(2,0));
        
        for(auto c : s){
            
            if(c == '1'){
                res += dp[1][0];
                ones++;
            }
            else{
                res += dp[0][1];
                zeros++;
            }
            
            if(c == '0'){
                dp[1][0] += ones;
                
            }
            else{
                dp[0][1] += zeros;
            }    
        }
        
        return res;
    }
};