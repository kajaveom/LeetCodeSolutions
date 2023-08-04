class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        
        //unordered_map<int,int> mp;
        // for(auto d : s)
        //     mp[d] = 0;
        int i = 0, j = 0, n = s.length(), dupCount = 0, res = INT_MIN;
        
        while(j < n && i <= j){
            
            //cout<<i<<" "<<j<<endl;
            
            if(j > 0 && s[j]==s[j-1])
                dupCount++;
            
            if(dupCount<=1){
                res = max(res, j-i+1);
                j++;
            }
            else if(dupCount > 1){
                while(i <= j && dupCount > 1){
                    if(s[i]==s[i+1])
                    dupCount--;
                    i++;
                }
                j++;
            }
            else
                j++;
        }
        
       return res;
    }
};