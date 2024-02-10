class Solution {
public:
    
    const int mod = 1e9+7;
    
    long long binaryExp(long long a, long long b) {
        long long res = 1;
        a = a;
        while (b) {
            if (b & 1)
                res = ((res % mod) * (a % mod)) % mod;
            a = ((a % mod) * (a % mod)) % mod;
            res = res % mod;
            b = b >> 1;
        }
        return (int)res;
    }
    
    int numberOfGoodPartitions(vector<int>& nums) {
        
        unordered_map<int,pair<int,int>> mp;
        
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = make_pair(i,i);
            }
            else{
                mp[nums[i]].second = i;
            }
        }
        
        int parts = 0, end_index = -1, i = 0;
        
        while(i < nums.size()){
            end_index = max(end_index, mp[nums[i]].second);
            if(i == end_index){
                parts++;
            }
            i++;
        }
        
        return binaryExp(2, parts-1);
        
    }
};