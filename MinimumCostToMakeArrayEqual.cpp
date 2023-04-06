//https://leetcode.com/problems/minimum-cost-to-make-array-equal/
long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l = *min_element(nums.begin(),nums.end());
        long long r=*max_element(nums.begin(),nums.end());
        long long sum2=0;
        while(l<=r)
        {
            long long mid = l + (r-l)/2;
            long long sum=0;
            sum2=0;
            for(int i=0;i<nums.size();i++)
            {
                sum += (abs(mid-nums[i])*(long long)cost[i]);
                sum2 += (abs(mid+1-nums[i])*(long long)cost[i]);
            }
            if(sum<=sum2)
            {
               r = mid-1;
               sum2 = sum;
            }
            else{
                l = mid+1;
            }
        }
        return sum2;

    }
