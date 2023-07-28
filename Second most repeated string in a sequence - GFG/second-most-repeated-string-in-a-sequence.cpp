//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int> mp;
        for(int i = 0; i < n; i++){
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]] = 1;
            }
            else
            mp[arr[i]]++;
        }
        int max = INT_MIN;
        for(int i= 0; i < n; i++){
            if(mp[arr[i]] > max){
                max = mp[arr[i]];
            }
        }
        int sec_max = INT_MIN;
        string res;
        for(int i = 0;  i< n; i++){
            if(mp[arr[i]] > sec_max && mp[arr[i]]!=max){
                sec_max = mp[arr[i]];
                res = arr[i];
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends