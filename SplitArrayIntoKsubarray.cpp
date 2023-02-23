// https://leetcode.com/problems/split-array-largest-sum/description/
int splitArray(vector<int>& nums, int k) {
        long long l = *max_element(nums.begin(),nums.end());
        long long h;
        accumulate(nums.begin(),nums.end(),h);
        int n = nums.size();
        long long ans=0;
        while(l<=h)
        {
            long long mid = l+(h-l)/2;
            long long cursum=0;
            int no_subarray=1;
            for(int i=0;i<n;i++)
            {
                if(cursum+nums[i]>mid)
                {
                    no_subarray++;
                    cursum = nums[i];
                }
                else
                cursum += nums[i];
            }
            if(no_subarray<=k)
            {
                ans=mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
