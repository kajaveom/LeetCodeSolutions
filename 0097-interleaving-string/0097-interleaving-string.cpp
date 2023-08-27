class Solution {
public:
    
    
    bool canForm(string &s1, string &s2, int i, int j, string &s3,
                        vector<vector<int>> &dp){
        
        
        if(i==s1.length() && j==s2.length())
            return true;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int w1 = false, w2 = false;
        
        //include s1
        if(i < s1.length() && s1[i] == s3[i+j])
            w1 = canForm(s1,s2,i+1,j,s3,dp);
        
        //include s2
        if(j < s2.length() && s2[j]== s3[i+j])
            w2 = canForm(s1,s2,i,j+1,s3, dp);
        
        return dp[i][j] = w1 | w2;
        
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.length() + s2.length() != s3.length())
            return false;

        // if(s1=="" && s2=="" && s3=="")
        //     return true;
        
        int n = s1.length() , m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        
        return canForm(s1,s2,0,0,s3,dp);
    }
};