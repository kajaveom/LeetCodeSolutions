class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        
        unordered_map<char,int> mp;
        
        for(int i = 0; i < chars.length(); i++){
            mp[chars[i]] = vals[i];
        }
        
        int max_ending_here = 0, max_till_now = INT_MIN;
        
        for(int i = 0; i < s.length(); i++){
            if(mp.find(s[i])!=mp.end()){
                max_ending_here += mp[s[i]];
            }
            else{
                max_ending_here += (s[i] - 'a') + 1;
            }
            
            if(max_ending_here > max_till_now){
                max_till_now = max_ending_here;
            }
            
            if(max_ending_here < 0)
                max_ending_here = 0;
        }
        
        if(max_till_now < 0)
            return 0;
        
        return max_till_now;
         
    }
};