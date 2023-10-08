class Solution {
public:
    
    
    int dp[501][501];
    
    int getMax(int i, int j,vector<int> &nums1, vector<int>& nums2){
    
        if(i >= nums1.size() || j >= nums2.size())
            return -1e9;
    
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        //cout<<i<<" "<<j<<" "<<nums1[i]<<" "<<nums2[j]<<endl;
            
        int maxi = INT_MIN;
        //consider i
        for(int k = j; k < nums2.size(); k++){
            int nextAns = getMax(i+1,k+1,nums1,nums2) ;
            if(nextAns>0)
                maxi = max(maxi, nums1[i]*nums2[k] + nextAns);
            else
                maxi = max(maxi, nums1[i]*nums2[k]);
        }
        
        //do not consider i
        int nextAns =  getMax(i+1,j,nums1,nums2);
        if(nextAns!=-1e9)
            maxi = max(maxi, nextAns);
        
        return dp[i][j] = maxi;
    }
    
    
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        memset(dp, -1, sizeof(dp));
        return getMax(0,0,nums1,nums2);
    }
};