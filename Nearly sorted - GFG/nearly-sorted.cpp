//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int k){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i <= k; i++){
            pq.push(arr[i]);
        }
        int index = 0;
        for(int i = k+1; i < num; i++){
            arr[index++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        while(!pq.empty()){
            arr[index++] = pq.top();
            pq.pop();
        }
        vector<int> ans(arr , arr+num);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends