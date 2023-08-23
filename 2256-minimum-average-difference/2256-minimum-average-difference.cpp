
#define ll long long int

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n = nums.size();
        vector<ll> pSum(n,0);
        pSum[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            pSum[i] = pSum[i-1] + nums[i];
        }
        
        ll mini = INT_MAX, res = -1;
        for(int i = 0; i < n; i++){
            ll avg_a = (pSum[i])/(i+1);
            ll avg_b = 0;
            if(i!=n-1)
            avg_b = (pSum[n-1] - pSum[i])/(n-i-1);
            
            if(mini > abs(avg_a - avg_b)){
                mini = abs(avg_a - avg_b);
                res = i;
            }
            
        }
        return res;
        
        
    }
};