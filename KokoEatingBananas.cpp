int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long l,r,sum=0,max_pile=0;
        for(int i=0;i<n;i++)
        {
            sum += ((piles[i]/h) + (piles[i]%h));
            max_pile = max((long long)piles[i],max_pile);
        }
        
        l = ((sum%h)==0)?(sum/h):((sum/h) + 1);
        r = max_pile;
        while(l<=r)
        {
            long long mid = l + (r-l)/2;
            long long h_per_pile = 0;
            for(int i=0;i<n;i++)
            {
                int rem = (piles[i]%mid == 0)? 0:1;
                h_per_pile += (piles[i]/mid)+rem;
            }
            if(h_per_pile <= h)
            r = mid-1;
            else
            l = mid+1;
        }
        return r+1;
    }
