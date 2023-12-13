class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        set<vector<int>> st;
        
        for(int i = 0; i < n; i++){
            int j = i+1;
            int k = n-1;
            
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    st.insert(vector<int>{nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
                
            }
        }
        
        vector<vector<int>> res;
        for(auto v : st)
            res.push_back(v);
        
        return res;
        
        
        
        
        
    }
};