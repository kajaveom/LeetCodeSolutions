class Solution {
public:
    
    // int dp[2001];

     bool isPalindrome(string &str,int s, int e){
    

       int i = s, j = e;
        while(i <= j){
            if(str[i]!=str[j])
            return false;
            i++; j--;
        }
        return true;
    }
    
    int cut(string &str, int s, int e, vector<int> &dp){
        
        if(s > e)
        return 0;
        
        if(dp[s]!=-1)
        return dp[s];
        
        
        int minCost = INT_MAX, cost = 0;
        for(int i = s; i <= e; i++){
            
            if(isPalindrome(str,s,i))
            {
                cost = 1 + cut(str,i+1,e,dp);
                minCost = min(minCost, cost);
            }
        }
        
        return dp[s] = minCost;
    }
    
    int minCut(string str) {
        
        int n = str.length();
        vector<int> dp(n+1, -1);
        
        return cut(str,0, str.length()-1, dp) - 1;
    }
};