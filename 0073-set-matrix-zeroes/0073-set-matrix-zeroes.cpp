class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rowZero = 0,colZero = 0, m = matrix.size(), n =matrix[0].size();
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n ; j++){
                
                if(matrix[i][j] == 0){
                    if(j == 0)
                        colZero = 1;
                    if(i==0)
                        rowZero = 1;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    
                }
            }
        }
        
        // for(auto a : matrix){
        //     for(auto b : a){
        //         cout<<b<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[0][j]==0 || matrix[i][0]==0)
                    matrix[i][j] = 0;
            }
        }
        
        if(rowZero){
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
        
        if(colZero){
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
        
    }
};