class NumMatrix {
public:
    
    vector<vector<int>> pSum{200, vector<int>(200,0)};
    
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        int i =0, j = 0;
        
       // cout<<"yes"<<endl;
        while(i < n){
            for(j = 0; j < m; j++){
                if(j > 0)
                pSum[i][j] += matrix[i][j] + pSum[i][j-1];
                else
                pSum[i][j] += matrix[i][j];
            }
            i++;
        }
        
       // cout<<"yes"<<endl;
        
        j = 0, i = 1;
        while(j < m){
            for(i = 1; i < n; i++){
                //cout<<i<<" "<<j<<endl;
                pSum[i][j] += pSum[i-1][j]; 
            }
            j++;
        }
        
//         cout<<"yes"<<endl;
        
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 cout<<pSum[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans = 0;
        ans += pSum[row2][col2];
        
        if(row1 > 0){
            ans -= pSum[row1-1][col2];
            if(col1 > 0){
                ans -= pSum[row2][col1-1];
                ans += pSum[row1-1][col1-1];
            }
        }
        else if(col1 > 0){
            ans -= pSum[row2][col1-1];
            if(row1 > 0){
                ans -= pSum[row1-1][col2];
                ans += pSum[row1-1][col1-1];
            }
        }
        
        return ans;
        
        
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */