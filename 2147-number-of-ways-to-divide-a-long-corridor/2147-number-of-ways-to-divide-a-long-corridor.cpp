class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int numberOfWays(string corridor) {
        
        vector<int> arr;
        long long tch = 0, ch = 0, res =1, len = 0, n = corridor.length();
        for(int i = 0; i < n; i++){
            char c = corridor[i];
            if(c=='S'){
                tch++;
                ch++;
            }
            
            if(ch>2){
                res = ((res*len) % mod);
                ch = 1;
                len = 0;
            }
            
            if(ch==2){
                len++;
            
            }
        }
        
        if(tch==0 || tch%2!=0)
            return 0;
        
        if(res < 0)
            res += mod;
        else
            res = res % mod;
        
        return res;
        
    }
};