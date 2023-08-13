class Solution {
public:
    string shortestCompletingWord(string lP, vector<string>& words) {
        
        unordered_map<char,int> mp;
        
        for(char c : lP){
            if(isalpha(c) && c!=' '){
                mp[tolower(c)]++;
            }
        }
        
        string res = "";
        
        for(auto w : words){
            unordered_map<char,int> tp;
            for(auto c : w){
                tp[c]++;
            }
            bool f = true;
            for(auto c : mp){
                // if(tp.find(c.first)==tp.end()){
                //     f = false;
                //     break;
                // }
                if(mp[c.first]>tp[c.first])
                {
                    f = false;
                    break;
                }
            }
            if(f){
                if(res==""){
                    res = w;
                }
                else if(res.length() > w.length())
                    res = w;
            }
        }
        
        return res;
        
    }
};