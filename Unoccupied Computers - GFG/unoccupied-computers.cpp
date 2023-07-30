//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, string s) {
        
        unordered_set<char> st;
        unordered_set<char> nt;
        int comps = 0, res = 0;
        for(int i = 0; i < s.length(); i++){
            if(st.find(s[i])==st.end()){
                if(comps==n){
                    if(nt.find(s[i])==nt.end()){
                        nt.insert(s[i]);
                       // cout<<s[i]<<endl;
                        res++;
                    }
                    else{
                        nt.erase(s[i]);
                    }
                }
                else if(nt.find(s[i])!=nt.end()){
                    nt.erase(s[i]);
                }
                else{
                    st.insert(s[i]);
                    comps++;
                }
            }
            else{
                st.erase(s[i]);
                comps--;
            }
        }
        
        return res;
       
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        cin.ignore();
        string s; 
        getline(cin,s);
        
        Solution obj;
        int res = obj.solve(n, s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends