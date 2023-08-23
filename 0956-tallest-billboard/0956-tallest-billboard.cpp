class Solution {
public:
    
    int dp[21][10001];
    int getMax(vector<int> &rods, int i, int diff){
        
        
        //cout<<leftSum<<" "<<rightSum<<endl;
        
        if(i == rods.size())
        {
            if(diff==0)
                return 0;
            return -1e9;
        }
        
        if(dp[i][diff+5000]!=-1)
            return dp[i][diff+5000];
        
        int w1 = getMax(rods,i+1,diff);
        int w2 = rods[i] + getMax(rods,i+1,diff+rods[i]);
        int w3 = rods[i] + getMax(rods,i+1,diff-rods[i]);
        
        return dp[i][diff+5000] = max({w1,w2,w3});
 
    }
    
    
    
    int tallestBillboard(vector<int>& rods) {
        
        memset(dp, -1, sizeof(dp));
        return (getMax(rods,0,0))/2;
    }
};