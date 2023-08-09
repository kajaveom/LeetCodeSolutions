class Solution {
public:
    
    int dp[601][101][101];
    int getMaxSubSet(vector<pair<int,int>> &pr, int m, int n, int k){
        
        if(m==0 && n==0)
            return 0;
        
        if(k < 0)
            return 0;
        
        if(dp[k][m][n]!=-1)
            return dp[k][m][n];
            
        if(pr[k].first > m || pr[k].second > n)
            return dp[k][m][n] = getMaxSubSet(pr,m,n,k-1);
        
        int w1 = 1 + getMaxSubSet(pr,m-pr[k].first,n-pr[k].second, k-1);
        int w2 = getMaxSubSet(pr,m,n,k-1);
        
        return dp[k][m][n] = max(w1,w2);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>> pr;
        memset(dp, -1, sizeof(dp));
        int k = strs.size();
        
        for(auto b : strs){
            int o = 0, z = 0;
            for(auto c : b){
                if(c=='0')
                    z++;
                else
                    o++;
            }
            pr.push_back(make_pair(z,o));
        }
        
        return getMaxSubSet(pr, m,n, k-1);
        
    }
};