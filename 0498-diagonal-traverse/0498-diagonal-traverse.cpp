class Solution {
public:
    
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<int> res;
        
        int up = 1;
        int i =0, j = 0, ele=0, tot = mat.size()*mat[0].size();
        
        while(ele < tot){
            
          //  cout<<i<<" "<<j<<endl;
            
            if(up){
                while(i >= 0 && j < mat[0].size()){
                    res.push_back(mat[i][j]);
                    ele++;
                    i--;
                    j++;
                }
                i++;
                up = !up;
                
                if(j >= mat[0].size()){
                    i++;
                    j--;
                }
            }
            else{
                while(i < mat.size() && j >= 0){
                    res.push_back(mat[i][j]);
                    ele++;
                    i++;
                    j--;
                }
                j++;
                up = !up;
                
                if(i >= mat.size()){
                    i--;
                    j++;
                }
            }
        }
        
        return res;
        
        
        
    }
};