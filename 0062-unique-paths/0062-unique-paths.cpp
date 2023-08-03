class Solution {
public:
    
    int uniquePaths(int m, int n) {
        
        vector<long long> memo(n+1,0);
        
        memo[1] = 1;
        
        //long long ans = 0;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(i==1 && j==1)
                    continue;
                memo[j] = memo[j] + memo[j-1];
            }
        }
        
        return memo[n];
        
        
    }
};