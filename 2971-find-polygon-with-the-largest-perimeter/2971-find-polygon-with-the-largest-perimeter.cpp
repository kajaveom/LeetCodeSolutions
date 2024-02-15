class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
         
        sort(nums.rbegin(), nums.rend());
        
         long long n = nums.size();
        vector< long long> pSum(n, 0);
        
        pSum[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            pSum[i] += pSum[i+1] + nums[i];
        }
        
         long long max_peri_poss = -1;
        
        for(int i = 0; i < nums.size()-2; i++){
            if(nums[i] < pSum[i+1]){
                max_peri_poss = max(max_peri_poss, nums[i] + pSum[i+1]);
            }
        }
        
        return max_peri_poss;
    }
};