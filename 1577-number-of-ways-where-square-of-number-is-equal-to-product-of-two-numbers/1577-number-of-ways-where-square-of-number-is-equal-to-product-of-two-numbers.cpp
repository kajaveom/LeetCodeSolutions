class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<long,int> m1;
        unordered_map<long,int> m2;
        
        for(int i = 0; i < nums1.size(); i++){
            long mul = (long)nums1[i]*nums1[i];
            if(m1.find(mul)==m1.end())
                m1[mul] = 1;
            else
                m1[mul] += 1;
        }
        
        for(int i = 0; i < nums2.size(); i++){
            long mul = (long)nums2[i]*nums2[i];
            if(m2.find(mul)==m2.end())
                m2[mul] = 1;
            else
                m2[mul] += 1;
        }
        
        int ans = 0;
        
        for(int i = 0; i < nums1.size(); i++){
            for(int j = i+1; j < nums1.size(); j++){
                long mul = (long)nums1[i]*nums1[j];
                if(m2.find(mul)!=m2.end())
                    ans += m2[mul];
            }
        }
        
        for(int i = 0; i < nums2.size(); i++){
            for(int j = i+1; j < nums2.size(); j++){
                long mul = (long)nums2[i]*nums2[j];
                if(m1.find(mul)!=m1.end())
                    ans += m1[mul];
            }
        }
        
        return ans;
        
        
        

    }
};