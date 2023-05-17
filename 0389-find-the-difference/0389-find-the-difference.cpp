class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(auto c : s){
            mp[c]++;
        }
        for(auto c : t){
            mp[c]--;
        }
        for(auto x : mp){
            if(x.second!=0)
            return x.first;
        }
        return '0';
    }
};