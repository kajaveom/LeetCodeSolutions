class Solution {
public:
    
    bool compare(string s1, string s2){
       
        if(s1.length() != s2.length()+1)
            return false;
        
        int cnt = 0, i = 0, j = 0;
        while(i<s1.length()){
            if(s1[i]==s2[j]){
                i++; j++;
            }
            else{
                i++;
            }
        }
        
        if(i==s1.length() && j==s2.length())
            return true;
        return false;
    }
    
    static bool myCmp(const string &s1, const string &s2){
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), myCmp);
        
        int n = words.size();
        vector<int> dp(n, 1);
        
//         for(auto a : words)
//             cout<<a<<" ";
//         cout<<endl;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(compare(words[i], words[j]) && 1+dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
        
    }
};