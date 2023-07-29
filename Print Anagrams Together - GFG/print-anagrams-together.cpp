//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
       
        unordered_map<string, pair<int,vector<string>>> mp;
        vector<vector<string>> res;
        for(auto s : string_list){
            string t = s;
            sort(s.begin(), s.end());
            if(mp.find(s)==mp.end()){
                mp[s] = make_pair(1, vector<string>{t});
            }
            else{
                mp[s].second.push_back(t);
            }
        }
        
        // for(auto x : mp){
        //     for(auto s : x.second.second)
        //     cout<<s<<" ";
        //     cout<<endl;
        // }
        
        for(auto s : string_list){
            sort(s.begin(), s.end());
            if(mp[s].first){
                mp[s].first = 0;
                res.push_back(mp[s].second);
            }
        }
        
        
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends