class Solution {
public:
    
    vector<int>par;
    vector<int>ran;
    int find_par(int node) {
        if(par[node] == node) {
            return node;
        }
        return par[node] = find_par(par[node]);
    }

    void merge(int a, int b) {
        if(ran[a] >= ran[b]) {      
            ran[a] += ran[b];
            par[b] = a;
        }
        else{
            par[a] = b;        
            ran[b] += ran[a];
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        par = vector<int>(n+1);
        ran = vector<int>(n+1, 1);
        
        for(int i=0; i<n; i++) {
            par[i] = i;
        }
        map<int,vector<int>>m;
        for(int i=0; i<n; i++) {
            int num = nums[i];
            if(nums[i] != 1) {
                m[nums[i]].push_back(i);
            }
            int k = sqrt(num);
            for(int j=2; j<=k; j++) {
                if(num%j == 0) {
                    m[j].push_back(i);
                    m[num/j].push_back(i);
                }
            }
        }
        
        for(auto it: m) {
            vector<int>v = it.second;
            if(v.size() >= 2) {

                for(int j=1; j<v.size(); j++) {

                    int a = find_par(v[j]);
                    int b = find_par(v[0]);
                    if(a == b) {
                        continue;
                    }
                    merge(a, b);     
                }
            }
        }
         int x = *max_element(ran.begin(), ran.end());
        if(x != n) {
            return false;
        }
        return true;
    }
};