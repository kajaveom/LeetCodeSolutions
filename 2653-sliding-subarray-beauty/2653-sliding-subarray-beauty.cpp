class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        vector<int> hash(51, 0);
        
        int negCount = 0, n = nums.size(), i = 0, j = 0;
        vector<int> ans;
        
        while(j < n){
            if(nums[j]<0)
            {    
                hash[(-1)*nums[j]]++;
                negCount++;
            }
            
            
            
            if(j - i +1 < k)
                j++;
            else{
                //cout<<i<<" "<<j<<" "<<negCount<<endl;
                if(negCount < x){
                    ans.push_back(0);
                }
                else{
                    int cnt = 0;
                    for(int f = 50; f >= 1; f--){
                        //cout<<hash[f]<<" ";
                        cnt += hash[f];
                        if(cnt >= x)
                        {
                            ans.push_back(-f);
                            break;
                        }
                    }   
                    
                    //cout<<cnt<<endl;
                }
                
                if(nums[i] < 0){
                    hash[(-1)*nums[i]]--;
                    negCount--;
                }
                    
                j++;
                i++;
            }
        }
        
        return ans;
        
        
        
    }
};