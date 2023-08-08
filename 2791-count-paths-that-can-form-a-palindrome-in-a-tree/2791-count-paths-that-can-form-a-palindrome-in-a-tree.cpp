class Solution {
public:
    
    vector<vector<pair<int,char>>> adj;
    unordered_map<int,int> mp;
    
    void dfs(int p, int path){
        mp[path]++;
        
        for(auto c : adj[p]){
            int val = c.first;
            int let = c.second - 'a';
            
            path ^= (1 << let);
            dfs(val,path);
            path ^= (1 << let);
        }
    }
    
    long long countPalindromePaths(vector<int>& parent, string s) {
        
        long long ans = 0;
        int n = parent.size();
        adj.resize(n);
        
        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(make_pair(i,s[i]));
        }
        
        
        dfs(0,0);
        
        for(auto f : mp){
            long long val = f.first, cnt = f.second;
            
            ans += ((cnt)*(cnt-1));
            
            for(int i = 0; i < 26; i++)
            {
                long long cur = val ^ (1 << i);
                if(mp.find(cur) != mp.end()){
                    ans += cnt * (mp[cur]);
                }
            }
        }
        
        ///ans = ceil((double)ans/2);
        
        return ans/2;
        
        
    }
};