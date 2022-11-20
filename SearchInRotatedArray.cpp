//https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-a-rotated-array
int i=l,j=h,peek=-1;
       while(i<=j)
       {
           int mid = i+(j-i)/2;
            if (mid < j && a[mid] > a[mid + 1])
           {
               peek=mid;
               break;
           }
           if (mid > i && a[mid] < a[mid - 1])
           {
               peek=mid-1;
               break;
           }
           if(a[mid]>=a[j])
           i=mid+1;
           else
           j=mid-1;
       }
       if(peek!=-1)
       peek=i;
       i=l,j=peek;
       while(i<=j)
       {
           int mid = i + (j-i)/2;
           if(a[mid]==key)
           return mid;
           else if(a[mid]>key)
           j = mid-1;
           else
           i = mid+1;
       }
       i=peek+1,j=h;
       while(i<=j)
       {
           int mid = i + (j-i)/2;
           if(a[mid]==key)
           return mid;
           else if(a[mid]>key)
           j = mid-1;
           else
           i = mid+1;
       }
       return -1;
    }
