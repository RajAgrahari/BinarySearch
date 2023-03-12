// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-93/problems/
int maxChocolates(int n, int m, vector<int> &arr) {
        long long sum=0;
        for(int i=0;i<n;i++)
        sum += arr[i];
        long long l=1,r=(sum/m);
        while(l<=r)
        {
            long long mid = l + (r-l)/2;
            long long temp=0;
            for(int i=0;i<n;i++)
            {
                temp += (arr[i]/mid);
            }
            if(temp>=m)
            l = mid+1;
            else
            r = mid-1;
        }
        return l-1;
    }
