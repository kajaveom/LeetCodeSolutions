class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        
        int rep = 0, sum = 0, miss = 0;
        unordered_set<int> st;
        for(auto a : nums)
        {
            if(st.find(a)!=st.end())
                rep = a;
            else
                st.insert(a);
            
            sum += a;
        }
        
        
        int n = nums.size();
        int asum = (n*(n+1))/2;
        
       // cout<<sum<<" "<<asum<<endl;
        
       if(sum > asum){
           miss = rep - abs(sum-asum);
       }
        else
            miss = rep + abs(sum-asum);
        
        
        return vector<int>{rep,miss};
        
        
    }
};