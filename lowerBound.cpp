 int findFloor(vector<long long> v, long long n, long long x){
        
       int l=-1,r=n;
        while(r>l+1)
        {
            int mid=l+(r-l)/2;
            if(v[mid]<=x)
            l=mid;
            else
            r=mid;
        }
        if(l!=-1 && v[l]<=x)
        return l;
        else
        return -1;
        
    }
