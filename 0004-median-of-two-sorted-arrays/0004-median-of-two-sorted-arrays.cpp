class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            
        
        int m = nums1.size(), n = nums2.size(), s , l;
        
        if(m==0){
            if(n%2==0){
                return (double)(nums2[n/2] + nums2[(n/2)-1])/2;
            }
            else
                return (double)(nums2[n/2]);
        }
        else if(n==0){
            if(m%2==0){
                return (double)(nums1[m/2] + nums1[(m/2)-1])/2;
            }
            else
                return (double)(nums1[m/2]);
        }
        
        int begin = 0,  end;
        
        auto itS = nums1.begin(), itL = nums2.begin();
        
        if(m < n){
            s = m;
            l = n;
            end = m;
        }
        else{
            s = n;
            l = m;
            end = n;
            itS = nums2.begin();
            itL = nums1.begin();
        }
            
        
        while(begin <= end){
            int i1 = (begin+end)/2;
            int i2 = (m+n+1)/2 - i1;
            
    
            
            int min1 = (i1==s)?INT_MAX:(*(itS + i1));

            int max1 = (i1==0)?INT_MIN:(*(itS + i1 -1));

            int min2 = (i2==l)?INT_MAX:(*(itL + i2));
  
            int max2 = (i2==0)?INT_MIN:(*(itL + i2 -1));
          
          
            if(max1 <= min2 && max2 <= min1){
                if((m+n)%2==0){
                    return (double)(max(max1,max2) + min(min1,min2))/2;
                }
                else
                    return (double)(max(max1,max2));
            }
            else if(max1 > min2){
                end = i1-1;
            }
            else{
                begin = i1 + 1;
            }
        }
        
        return 0;
        
            
    }
};