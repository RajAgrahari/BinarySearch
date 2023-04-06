//https://leetcode.com/problems/minimum-cost-to-make-array-equal/
long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int mx = *max_element(nums.begin(),nums.end());
        long long mxsum = 0;
        for(int i=0;i<cost.size();i++)
        mxsum += (abs(nums[i]-mx)*cost[i]);

        long long l = *min_element(nums.begin(),nums.end());
        long long r=mx;
        while(l<=r)
        {
            long long mid = l + (r-l)/2;
            long long sum=0;
            for(int i=0;i<nums.size();i++)
            {
                sum += (abs(mid-nums[i])*(long long)cost[i]);
            }
            if(sum<=mxsum)
            {
               r = mid-1;
               mxsum = sum;
            }
            else{
                l = mid+1;
            }
        }
        return r+1;

    }
