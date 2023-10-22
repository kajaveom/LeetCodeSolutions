class Solution {
public:
    string longestPalindrome(string s) {
        
        int n= s.length(), maxi = 1, st=0,ed = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        
        for(int i = 0; i < n-1; i++){
            if(s[i]==s[i+1]){
                st = i;
                ed = i+1;
                maxi = 2;
                dp[i][i+1] = 1;
            }
                
        }
        
        for(int gap = 2; gap < n; gap++){
            for(int i = 0; i < n-gap; i++){
                int j = i+gap;
                if(s[i]==s[j] && dp[i+1][j-1]==1)
                {
                    dp[i][j] = 1;
                    maxi = max(maxi, j-i+1);
                    st = i;
                    ed = j;
                }
            }
        }
        
        return s.substr(st,ed-st+1);
        
    }
};