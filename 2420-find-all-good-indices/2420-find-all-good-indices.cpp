class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> lS(n, 0);
        vector<int> rS(n, 0);
        lS[0] = 1;
        for(int i = 1; i < n; i++){
           if(nums[i] <= nums[i-1]){
               lS[i] = lS[i-1] + 1;
           }
            else{
                lS[i] = 1;
            }
        }
        rS[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] <= nums[i+1]){
               rS[i] = rS[i+1] + 1;
           }
            else{
                rS[i] = 1;
            }
        } 
        vector<int> ans;
        for(int i = k; i < n-k; i++){
            if(lS[i-1] >= k && rS[i+1]>= k)
                ans.push_back(i);
        }
        return ans;
    }
};