class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        
        int xorSum = 0, n = nums.size();
        long long int res = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            xorSum ^= nums[i];
            if(mp.find(xorSum)==mp.end()){
                mp[xorSum] = 1;
            }
            else{
                res += mp[xorSum];
                mp[xorSum]++;
            }
        }
        
        return res;
        
        
    }
};