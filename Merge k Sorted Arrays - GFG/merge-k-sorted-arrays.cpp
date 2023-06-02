//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    
    struct triplet{
        int val;
        int i,j;
        
        triplet(int a, int b, int c)
        {
            val = a;
            i = b;
            j = c;
        }
    };
    
    struct myCmp{
        bool operator()(triplet a, triplet b){
            return a.val > b.val;   
        }
    };
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
       priority_queue<triplet, vector<triplet>, myCmp> pq;
       for(int i = 0; i < arr.size(); i++){
           triplet t(arr[i][0], i, 0);
           pq.push(t);
       }
       vector<int> ans;
       while(!pq.empty()){
           ans.push_back(pq.top().val);
           if(pq.top().j < arr[pq.top().i].size()-1){
               triplet t(arr[pq.top().i][pq.top().j+1],pq.top().i,pq.top().j+1);
               pq.push(t);
           }
           pq.pop();
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends