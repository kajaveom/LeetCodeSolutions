class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
     
        long long n = nums.size();
        long long tot_pairs = (n*(n-1))/2;
        
        unordered_map<long long,int> mp;
        
        for(int i = 0; i < n; i++){
            long long diff = nums[i] - i;
            if(mp.find(diff)!=mp.end()){
                tot_pairs -= mp[diff];
                mp[diff]++;
            }
            else{
                mp[diff] = 1;
            }
        }
        
        return tot_pairs;
        
        
    }
};