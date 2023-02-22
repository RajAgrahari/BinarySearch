int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int totalLoad = 0, maxLoad = 0;
        for (int weight : weights) 
        {
            totalLoad += weight;
            maxLoad = max(maxLoad, weight);
        }
        int l = maxLoad, r = totalLoad;
          while(l<=r)
          {
              int mid = l + (r-l)/2;
              int k=0,cursum=0;
              for(int j=0;j<n;j++)
              {
                  cursum += weights[j];
                  if(cursum>mid)
                  {
                      if(weights[j]>mid)
                      break;
                      cursum = weights[j];
                      k++;
                  }
                  if(k>days)
                  break;
              }
              if(k<days && cursum<=mid)
              r = mid-1;
              else
              l = mid+1;
          }
          return r+1;
    }
