class Solution {
public:
    
    int dp[602][101][101];
//     int getMaxSubSet(vector<pair<int,int>> &pr, int m, int n, int k){
        
//         if(m==0 && n==0)
//             return 0;
        
//         if(k < 0)
//             return 0;
        
//         if(dp[k][m][n]!=-1)
//             return dp[k][m][n];
            
//         if(pr[k].first > m || pr[k].second > n)
//             return dp[k][m][n] = getMaxSubSet(pr,m,n,k-1);
        
//         int w1 = 1 + getMaxSubSet(pr,m-pr[k].first,n-pr[k].second, k-1);
//         int w2 = getMaxSubSet(pr,m,n,k-1);
        
//         return dp[k][m][n] = max(w1,w2);
//     }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>> pr;
        memset(dp, 0, sizeof(dp));
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
        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                dp[0][m][n] = 0;
            }
        }
        
        for(int i = 0; i <= k; i++){
            dp[i][0][0] = 0;
        }
        
        
        for(int k1 = 1; k1 <= k ; k1++){
            for(int m1 = 0; m1 <= m; m1++){
                for(int n1 = 0; n1 <= n; n1++){
                    
                    if(pr[k1-1].first > m1 || pr[k1-1].second > n1){
                        dp[k1][m1][n1] = dp[k1-1][m1][n1];
                    }
                    else{
                        int w1 = 1 + dp[k1-1][m1-pr[k1-1].first][n1-pr[k1-1].second];
                        int w2 = dp[k1-1][m1][n1];

                        dp[k1][m1][n1] = max(w1,w2);
                    }                
    
                }
            }
        }
        
        
        
        
        return dp[k][m][n];
        
    }
};