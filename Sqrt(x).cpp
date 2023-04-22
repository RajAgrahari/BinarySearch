//https://leetcode.com/problems/sqrtx/description/
int mySqrt(int x) 
    {
        if(x==0 || x==1)
        return x;
        long long l = 1;
        long long r = (x/2);
        while(l<=r)
        {
            long long mid = l+(r-l)/2;
            if(mid*mid <= x)
            l = mid+1;
            else
            r = mid-1;
        }
        return l-1;
    }
