// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array
int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
         if(n>m)
         kthElement(arr2,arr1,m,n,k);
         int l=max(0,k-m),r = min(k,n);
         while(l<=r)
         {
             int cut1 = (r+l)/2;
             int cut2 = k-cut1;
             
             int left1 = (cut1==0) ? INT_MIN : arr1[cut1-1];
             int left2 = (cut2==0) ? INT_MIN : arr2[cut2-1];
             int right1 = (cut1==n) ? INT_MAX : arr1[cut1];
             int right2 = (cut2==m) ? INT_MAX : arr2[cut2];
             if(left1 <= right2 && left2 <= right1)
            {
                return max(left1,left2);
            }
            else if(left1 > right2)
            {
                r = cut1-1;
            }
            else{
                l = cut1+1;
            }
             
         }
         return -1;
        
    }
