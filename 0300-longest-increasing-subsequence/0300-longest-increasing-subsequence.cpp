class Solution {
public:

    int ceilIndex(vector<int> arr, int s, int e, int x){

        
        while(s != e)
        {
            int mid = (s + e)/2;
            if(x <= arr[mid]){
                e = mid;
            }else{
                s = mid+1;
            }
        }
        
        return s;
    }


    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size(), res = 1;
        vector<int> lis(n, 0);
        lis[0] = nums[0];

        for(int i = 1; i < n; i++){
            
            //cout<<i<<" "<<res<<endl;
            
            if(nums[i] > lis[res-1])
            {
                lis[res] = nums[i];
                res++;
            }
            else{
                //cout<<"Loop"<<endl;
                int indx = ceilIndex(lis, 0, res-1, nums[i]);
                //cout<<"Loop"<<endl;
                if(lis[indx] > nums[i])
                lis[indx] = nums[i];
            }
        }

        return res;


    }
};