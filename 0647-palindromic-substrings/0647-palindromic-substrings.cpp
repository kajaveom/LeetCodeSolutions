class Solution {
public:
    int countSubstrings(string s) {
        
        int res = 0, n = s.length();
        
        vector<vector<int>> dp(n, vector<int>(n,0));
        
        for(int len = 1; len <= n; len++){
            
            for(int i = 0; i + len <= n; i++){
                
                int j = i + len - 1;
                
                if(i == j){
                    dp[i][j] = 1;
                    res++;
                }
                else if(i+1 == j){
                    if(s[i]==s[j])
                    {
                        dp[i][j] = 1;
                        res++;
                    }
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = 1;
                        res++;
                    }
                }
            }
            
        }
        
        return res;
        
        
        
        
    }
};