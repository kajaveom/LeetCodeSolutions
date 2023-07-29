//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        int uC = 0;
        unordered_map<char,int> mp;
        
        // cout<<'z'-'A'<<endl;
        
        for(int i = 0; i < str.length(); i++){
            if(mp.find(str[i])==mp.end())
            uC++;
            mp[str[i]] = 1;
        }
        
        //cout<<uC<<endl;
        
        for(int i = 0; i <  256 ; i++)
        mp[str[i]] = 0;
        
        int i = 0, j = 0, count = 0, res = INT_MAX;
        while(1){
            
        
        //    cout<<i<<" "<<j<<" "<<count<<endl;
            
            if(count < uC){
                if(mp[str[j]] == 0)
                {
                    count++;
                }
                mp[str[j]]++;
                j++;
            }
            
            if(count >= uC){
                res = min(res, j-i);
                //cout<<"res is : "<<res<<endl;
                mp[str[i]]--;
                if(mp[str[i]] == 0)
                count--;
                i++;
            }
            
            if(j>= str.length() && count<uC)
            break;
            
            if(i>= str.length())
            break;
        }
        
        return res;
        
        
        
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends