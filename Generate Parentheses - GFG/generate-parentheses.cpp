//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    
    void genAll(vector<string> &res, string s, int m, int n){
        
        if(n==0){
            if(m==0){
                res.push_back(s);
            }
            return;
        }
        
        genAll(res,s+"(",m+1,n-1);
        if(m!=0)
        genAll(res,s+")",m-1,n-1);
        
        return;   
    }
    
    
    vector<string> AllParenthesis(int n) 
    {
        vector<string> res;
        genAll(res,"",0,2*n);
        
        return res;
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
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends