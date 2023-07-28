//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    int minFlip1 = 0, minFlip2 = 0,o = 1, z = 1;
    for(int i = 0; i < S.length(); i++){
        if(z && S[i]=='1')
        {
            minFlip1++;
        }
        else if(!z && S[i]=='0')
        {
            minFlip1++;
        }
        z = !z;
    }
    
    for(int i = 0; i < S.length(); i++){
        if(o && S[i]=='0')
        {
            minFlip2++;
        }
        else if(!o && S[i]=='1')
        {
            minFlip2++;
        }
        o = !o;
    }
    
    return min(minFlip1, minFlip2);
}