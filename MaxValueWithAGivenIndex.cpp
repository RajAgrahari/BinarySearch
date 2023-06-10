//https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/
int maxValue(int n, int index, int maxSum) 
    {
        long long l = 1,r = maxSum;
        while(l<=r)
        {
            long long mid = l + (r-l)/2;
            long long count = 0;
            if (mid > index) 
            {
            count += (long)(mid + mid - index) * (index + 1) / 2;
            } 
            else 
            {
            count += (long)(mid + 1)*mid/2 + index - mid + 1;
            }
        
            if (mid >= n-index) 
            {
            count += (long)(mid+mid-n+1+index)*(n-index)/2;
            } 
            else 
            {
            count += (long)((mid + 1)*mid)/2 + n - index - mid;
            }   

            // cout<<sum<<endl;
            if(count-mid > maxSum)
            r = mid-1;
            else
            l = mid+1;
        }
        return l-1;
    }
