class Solution {
public:

    
    int addMinimum(string word) {
     
        int res = 0, n = word.length();
        vector<vector<int>> dp{
            { 0,1,2},
            { 2,0,1},
            { 1,2,0},
            {0,1,2}
        };
        
        if(word[0]=='b')
            res += 1;
        else if(word[0]=='c')
            res += 2;
    
        for(int i = 1; i < n; i++){
            int prev = word[i-1]-'a'+1;
            int cur = word[i] - 'a';
            res += dp[prev][cur];
        }
        
        if(word[n-1]=='a')
            res += 2;
        else if(word[n-1]=='b')
            res += 1;
        
        
        return res;
    }
};