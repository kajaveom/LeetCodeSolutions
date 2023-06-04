//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minimumStep(int n){
        
        int s = n, ans = 0;
        while(1){
            if(s%3!=0)
            s--;
            else
            s /= 3;
            ans++;
            
            if(s==1)
            break;
        }
        
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends