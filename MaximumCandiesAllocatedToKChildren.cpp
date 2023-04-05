//https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
int maximumCandies(vector<int>& candies, long long k) 
    {
         int l = 1;
         int r = *max_element(candies.begin(),candies.end());
         while(l<=r)
         {
             int mid = l + (r-l)/2;
             long long cnt=0;
             for(int i=0;i<candies.size();i++)
             {
                cnt += (candies[i]/mid);
             }
             if(cnt>=k)
             l = mid+1;
             else
             r = mid-1;
         }
         return l-1;
    }
