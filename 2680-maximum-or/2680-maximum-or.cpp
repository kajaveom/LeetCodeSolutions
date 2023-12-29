class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n==1){
            return nums[0] * pow(2,k); 
        }
        
        vector<long long> pref(n,0);
        vector<long long> suff(n,0);
        
        pref[0]=  nums[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] | nums[i];
        }
        
        suff[n-1] = nums[n-1];
        for(int i= n-2; i >= 0; i--){
            suff[i] = suff[i+1] | nums[i];
        }
        
        
        long long maxi = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            long long left = 0, right = 0;
            if(i==0){
                right = suff[i+1];
            }
            else if(i == n-1){
                left = pref[i-1];
            }
            else{
                left = pref[i-1];
                right = suff[i+1];
            }
            
            long long new_num = nums[i] * (pow(2, k));
            
            maxi = max(maxi , left | right | new_num);
            
        }
        
        return maxi;
        
        
    }
};