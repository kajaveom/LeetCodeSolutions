class Solution {
public:
    
    bool canReach(vector<int> &stones, int i, int u, int pos,vector<vector<int>> &dp){
        
       // cout<<i<<" "<<u<<" "<<pos<<endl;
        
        if(i >= stones.size())
             return false;
        
        if(stones[i] < pos)
            return canReach(stones,i+1,u,pos,dp);
        
        if(stones[i] != pos)
            return false;
      
        if(i==stones.size()-1 && stones[i] == pos)
            return true;
        
        if(dp[i][u]!=-1)
            return dp[i][u];
       
        
        int op1 = canReach(stones,i+1,u+1,stones[i]+u+1,dp);
        int op2 = canReach(stones,i+1,u,stones[i] + u,dp);
        int op3 =canReach(stones,i+1,u-1,stones[i] + u-1,dp);
       
        return dp[i][u] = op1 | op2 | op3;
        
    }
    
    
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return canReach(stones,1,1,stones[0]+1,dp);
    }
};