 int n = arr.size();
        if(n==0)
        return {-1,-1};
        int l=-1,r=n;
    int first=0,last=0;
    while((l+1)<r)
    {
        int mid = l + (r-l)/2;
        if(arr[mid]<target)
        l = mid;
        else
        {
            r = mid; 
        }
    }
    if(r!=n)
    first = r;
    l=-1,r=n;
    while((l+1)<r)
    {
        int mid = l + (r-l)/2;
        if(arr[mid]<=target)
        l = mid;
        else
        {
          r = mid; 
        }
    }
    if(l!=-1)
    last=l;
    if(arr[first]!=target || arr[last]!=target)
    return {-1,-1};
    return {first,last};
    }
