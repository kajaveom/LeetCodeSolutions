class Solution {
public:
    
    bool isSafe(int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m)
            return false;
        return true;
    }
    
    int count_neigh(vector<vector<int>> &b, int i, int j, int n, int m){
        vector<vector<int>> dir{{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};
        
        int ones = 0;
        for(auto d : dir){
            if(isSafe(i+d[0], j + d[1], n,m)){
                if(b[i+d[0]][j+d[1]] >= 0){
                    ones++;
                }
            }
        }
        
        return ones;
    }
    
    
    
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size(), m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0)
                    board[i][j] = -1;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(board[i][j] >= 0){
                    int n_ones = count_neigh(board,i,j,n,m);
                    
                    board[i][j] = n_ones;
                }
                else{
                    int n_ones = count_neigh(board,i,j,n,m);
                    
                    if(n_ones==0){
                        board[i][j] = -1;
                    }
                    else{
                        board[i][j] = (-1)*n_ones;
                    }    
                }
            }    
        }
        
        
//         for(auto a : board){
//             for(auto b : a)
//                 cout<<b<<" ";
//             cout<<endl;
//         }
        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(board[i][j] >= 0){
                    if(board[i][j]!=2 && board[i][j]!=3)
                        board[i][j] = 0;
                    else
                        board[i][j] = 1;
                }
                else{
                    if(board[i][j] == -3)
                        board[i][j] = 1;
                    else
                        board[i][j] = 0;
                }
                
            }
        }
        
        //return board;
        
        
        
    }
};