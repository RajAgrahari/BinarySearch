// https://leetcode.com/problems/minimum-time-to-complete-trips/
long long minimumTime(vector<int>& time, int totalTrips) 
{

         long long l=1,r=(1LL)**max_element(time.begin(),time.end())*totalTrips;
         long long ans=totalTrips;
         while(l<=r)
         {
            long long mid = l+(r-l)/2;
            long long tot = 0;
            for(int i=0;i<time.size();i++)
            {
               tot += (mid/time[i]);
            }
            if(tot >= totalTrips)
            {
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
         }
         return ans;
}
