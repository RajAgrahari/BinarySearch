//https://leetcode.com/contest/weekly-contest-340/problems/minimize-the-maximum-difference-of-pairs/
int minimizeMax(vector<int>& nums, int p) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=nums.back()-nums[0];
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int c=0;
            for(int i=0;i<n-1;i++)
            {
                if((nums[i+1]-nums[i])<=mid)
                {
                    c++;
                    i++;
                }
            }
            if(c<p)
            l = mid+1;
            else
            r = mid-1;
        }
        return r+1;
    }
