class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.length(), m = str2.length();
        vector<vector<string>> lcs(n+1, vector<string>(m+1, ""));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] == str2[j-1])
                {
                    lcs[i][j] = lcs[i-1][j-1] + str1[i-1];
                    // s1_indexes.push_back(i-1);
                    // s2_indexes.push_back(j-1);
                }
                else{
                    if(lcs[i-1][j].length() > lcs[i][j-1].length())
                        lcs[i][j] = lcs[i-1][j];
                    else
                        lcs[i][j] = lcs[i][j-1];
                }
            }
        }
        
        // for(int i = 0; i <= n; i++){
        //     for(int j = 0; j <= m; j++){
        //         cout<<lcs[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        string lcs_string = lcs[n][m], res = "";
        int lcs_index = 0;
        int i = 0, j = 0;
        
        while(lcs_index < lcs_string.length()){
            
            while(i < n){
                if(str1[i] == lcs_string[lcs_index]){
                    i++;
                    break;
                }
                res += str1[i];
                i++;
            }
            
            while(j < m){
                if(str2[j] == lcs_string[lcs_index]){
                    j++;
                    break;
                }
                res += str2[j];
                j++;
            }
            
            res += lcs_string[lcs_index];
            
            lcs_index++;   
        }
        
        //cout<<res<<endl;
        
       // cout<<i<<" "<<j<<" "<<n<<" "<<m<<endl;
        
        while(i < n){
            res += str1[i];
            i++;
        }
        
        while(j < m){
            res += str2[j];
            j++;
        }
        
        
        
        
        return res;
    }
};