//https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
        sort(arr,arr+n);
        int ans1,ans2;
        int l=-1,r=n;
        while(r>(l+1))
        {
            int mid=l+(r-l)/2;
            if(arr[mid]<x)
            l=mid;
            else
            r=mid;
        }
        if(r!=n && arr[r]>=x)
        ans1 = r;
        else
        ans1 = -1;
        
        l=-1,r=n;
        while(r>(l+1))
        {
            int mid=l+(r-l)/2;
            if(arr[mid]<=x)
            l=mid;
            else
            r=mid;
        }
        if(l!=-1 && arr[l]<=x)
        ans2 = l;
        else
        ans2 = -1;
        
        if(ans1==-1)
        return {arr[ans2],-1};
        else if(ans2==-1)
        return {-1,arr[ans1]};
        else
        return {arr[ans2],arr[ans1]};
        
}
