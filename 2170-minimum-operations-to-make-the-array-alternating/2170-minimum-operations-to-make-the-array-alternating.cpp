class Solution {
public:
    
    int not_equal(vector<int> &nums, int a, int i){
        int c = 0;
        for(int j = i; j < nums.size(); j+=2)
        {
            if(nums[j]!=a)
                c++;
        }
        
        return c;
    }
    
    int minimumOperations(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i = 0; i < n; i+=2){
            mp1[nums[i]]++;
        }
        
        for(int i =1; i < n; i+=2){
            mp2[nums[i]]++;
        }
        
        
        
        int maxi1 = 0, maxi2 = 0, sec_maxi1= 0, sec_maxi2 = 0, maxi_cnt = 0;
        for(auto m : mp1)
        {
            if(m.second > maxi_cnt){
                maxi_cnt = m.second;
                maxi1 = m.first;
            }
        }
        
        
        maxi_cnt = 0;
        for(auto m : mp2){
            if(m.second > maxi_cnt){
                maxi_cnt = m.second;
                maxi2 = m.first;
            }
        }
        
        if(maxi1 != maxi2){
            return not_equal(nums, maxi1, 0) + not_equal(nums,maxi2,1);
        }
        
        maxi_cnt = 0;
        for(auto m : mp1){
            if(m.second > maxi_cnt && m.first!=maxi1)
            {
                sec_maxi1 = m.first;
                maxi_cnt = m.second;
            }
        }
        
        maxi_cnt = 0;
        for(auto m : mp2){
            if(m.second > maxi_cnt && m.first!=maxi2)
            {
                sec_maxi2 = m.first;
                maxi_cnt = m.second;
            }
        }
        

        return min( not_equal(nums,sec_maxi1,0) + not_equal(nums,maxi2, 1) , 
                     not_equal(nums,maxi1,0) + not_equal(nums,sec_maxi2, 1) );
        
   
        
    }
};