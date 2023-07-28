//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        if(S.size() %2 != 0 ) 
        return -1;
        
         int c = 0, o = 0, res = 0;
        for(int i = 0 ; i < S.size(); i++)
        {
            if(S[i] == '[')
            {
                if(c > o ) 
                res += (c - o); 
                o++ ;
            }
            else{
                o--;
            }
        }
        return res ;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends