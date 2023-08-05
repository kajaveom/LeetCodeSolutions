class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        
        int n = arr.size();
        unordered_map<int,int> mp;
        mp[arr[n-1]] = 1;
        
        int res = 1;
        for(int i = n-2; i>= 0; i--){
            if(mp.find(arr[i] + d)!=mp.end()){
                mp[arr[i]] = mp[arr[i]+d]+1;
                res = max(res, mp[arr[i]]);
            }
            else{
                mp[arr[i]] = 1;
            }
        }
        
        return res;
        
        
        
        
    }
};