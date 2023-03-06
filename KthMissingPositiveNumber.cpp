// https://leetcode.com/problems/kth-missing-positive-number/description/
T.C. = O(log(N)) S.C. = O(1)
int findKthPositive(vector<int>& arr, int k) 
    {
        int n = arr.size();
        int l=0,r=n-1,ans=-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if((arr[mid]-(mid+1))<k)
            {
                l = mid+1;
            }
            else{
                if(mid>0)
                ans = arr[mid-1];
                else
                ans = 0;
                r = mid-1;
            }

        }
        if(ans==-1)
        ans=arr[r];
        int x = ans;
        for(int i=0;i<k-(ans-r-1);i++)
        x++;
        return x;
    }
