//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 bool search(vector<int>& arr, int key) {
       int l=0,h=arr.size()-1;
       while(l<=h)
       {
            int mid = l + (h-l)/2;
            if(arr[mid]==key)
            return true;
            if((arr[l] == arr[mid]) && (arr[h] == arr[mid]))
            {
                l++;
                h--;
            }
            else if(arr[mid]<arr[l])
            {
                if(key>arr[mid] && key<=arr[h])
                l=mid+1;
                else
                h=mid-1;
            }
            else{
                    if(key<arr[mid] && key>=arr[l])
                    h=mid-1;
                    else
                    l=mid+1;
                }
        }
        return false;
    }
