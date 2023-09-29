class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int maxi = 0;
        unordered_map<int,int> mp;
        
        for(int i = 0;  i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        // for(auto m : mp){
        //     cout<<m.first<<" "<<m.second<<endl;
        // }
        
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] <= 0)
                continue;
            mp[nums[i]]--;
            
            if(mp.find(k - nums[i])!=mp.end() && mp[k-nums[i]]>0){
                mp[k-nums[i]]--;
                maxi++;
            }
            else{
                mp[nums[i]]++;
            }
        }
        
        return maxi;
        
        
    }
};