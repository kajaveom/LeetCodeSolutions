class Solution {
public:
    
    vector<int> p;
    vector<int> r;
    vector<int> minCost;
    
    int find(int x){
        if(x == p[x])
            return x;
        p[x] = find(p[x]);
        return p[x];
    }
    
    
    void unin(int x, int y, int n){
        int px = find(x), py = find(y);
        if(px==1 || px == n){
            p[py] = px;
        }
        else if(py==1 || py==n){
            p[px] = py;
        }
        else if(r[px] > r[py]){
            p[py] = px;
        }
        else if(r[py] > r[px]){
            p[px] = py;
        }
        else{
            p[px] = py;
            r[py]++;
        }   
    }
    
    
    int minScore(int n, vector<vector<int>>& roads) {
        p.resize(n+1,0);
        r.resize(n+1,0);
        minCost.resize(n+1,INT_MAX);
        
        for(int i = 1; i <= n; i++){
            p[i] = i;
        }
        
        int res = INT_MAX;
        
        for(auto e : roads){
            unin(e[0], e[1], n);
            
         //   cout<<e[0]<<" "<<e[1]<<endl;
            // for(int i = 1; i <= n; i++)
            //     cout<<p[i]<<" ";
            // cout<<endl<<endl;
            
        }
        
        for(auto e : roads){
            int px = find(e[0]);
            int py = find(e[1]);
            
            if(px==1 || py==1 || px == n || py == n)
                res = min(res, e[2]);
        }
        
        return res;
    }
};