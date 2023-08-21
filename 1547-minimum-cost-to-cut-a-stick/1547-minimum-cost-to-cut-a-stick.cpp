class Solution {
public:
    
    int dp[103][103];
    int getMinCost(vector<int> &cuts, int i, int j){
        
        if(i > j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int mini = INT_MAX;
        for(int k = i; k <= j; k++){
            mini = min(mini, cuts[j+1] - cuts[i-1] + getMinCost(cuts,i,k-1) + getMinCost(cuts,k+1,j) );
        }
        
        return dp[i][j] = mini;
        
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int len = cuts.size();

        memset(dp, -1, sizeof(dp));
        
        return getMinCost(cuts, 1, len-2);
        
        
    }
};