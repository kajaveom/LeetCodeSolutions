class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i = 0, j = 0,  maxLen = 0, n = s.length();
        unordered_map<char,int> mp;
        
        while(j < n){
            //cout<<j<<endl;
            mp[s[j]]++;
            if(mp[s[j]] > 1){
               // cout<<i<<" "<<j<<endl;
                maxLen = max(maxLen , j-i);
                while(mp[s[j]]>1)
                {
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
            else{
                j++;
            }
        }
        
        maxLen = max(maxLen, j-i);
        
        return maxLen;
        
    }
};