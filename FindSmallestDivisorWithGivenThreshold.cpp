int smallestDivisor(vector<int>& nums, int threshold) {
        int l,r,max_divisor=0,n = nums.size();
        for(int i=0;i<n;i++)
        max_divisor = max(max_divisor,nums[i]);

        l = 1,r = max_divisor;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int div_per_ele = 0;
            for(int i=0;i<n;i++)
            {
                div_per_ele  += ceil((1.0*nums[i])/mid);
            }
            if(div_per_ele <= threshold)
            {
               r = mid-1;
            }
            else
            l = mid+1;
        }
        return r+1;
    }
