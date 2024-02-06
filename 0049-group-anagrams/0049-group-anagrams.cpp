class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(auto s : strs){
            string tmp  = s;
            sort(s.begin(), s.end());
            if(mp.find(s) == mp.end())
            mp[s] = vector<string>{tmp};
            else
            mp[s].push_back(tmp);
        }
        for(auto v : mp){
            vector<string> t;
            for(auto s : v.second)
            t.push_back(s);
            ans.push_back(t);
        }
        return ans;
    }
};