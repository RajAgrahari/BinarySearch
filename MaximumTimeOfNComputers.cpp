//https://leetcode.com/problems/maximum-running-time-of-n-computers/description/
long long maxRunTime(int n, vector<int>& batteries) 
    {
        int m = batteries.size();
        long long l = 1;
        long long h = 0;
        h = accumulate(batteries.begin(),batteries.end(),h);
        h = (h/n);
        while(l<=h)
        {
            long long mid = l + (h-l)/2;
            long long sum = 0;
            for(int i=0;i<m;i++)
            {
                sum += min((long long)batteries[i],mid);
            }
            if(sum>=((long long)n*mid))
            l = mid+1;
            else
            h = mid-1;
        }
        return l-1;

    }
