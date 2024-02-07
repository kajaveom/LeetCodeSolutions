class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        vector<vector<int>> cnt;
        string ans = "";
        for(int i = 0; i < s.length() ; i++)
            mp[s[i]]++;
        for(auto x : mp){
            cnt.push_back(vector<int>{x.second,x.first+0});
        }
        sort(cnt.rbegin(),cnt.rend());
        for(auto x : cnt)
        {
            int c = x[0];
            while(c--)
            ans += char(x[1]);
        }
 
        return ans;

    }
};