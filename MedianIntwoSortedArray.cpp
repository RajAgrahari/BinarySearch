// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
double findMedianSortedArrays(vector<int>& array1, vector<int>& array2) 
    {
        if(array1.size() > array2.size())
        return findMedianSortedArrays(array2,array1);
        int n = array1.size();
        int m = array2.size();
        int low = 0,high = n;
        while(low<=high)
        {
            int cut1 = (low+high)>>1;
            int x = (n+m+1)/2;
            int cut2 = x - cut1;
            int left1 = (cut1==0) ? INT_MIN : array1[cut1-1];
            int left2 = (cut2==0) ? INT_MIN : array2[cut2-1];
            int right1 = (cut1==n) ? INT_MAX : array1[cut1];
            int right2 = (cut2==m) ? INT_MAX : array2[cut2];
            
            
            if(left1 <= right2 && left2 <= right1)
            {
                if((n+m)%2 == 0)
                return (max(left1,left2) + min(right1,right2))/2.0;
                else
                return max(left1,left2);
            }
            else if(left1 > right2)
            {
                high = cut1-1;
            }
            else{
                low = cut1+1;
            }
        }
        return 0.0;
        
    
    }
