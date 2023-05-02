//https://practice.geeksforgeeks.org/problems/0a7c7f1089932257071f9fa076f25d353f91e0fd/1
int maxSweetness(vector<int>& sweetness, int n, int k) 
    {
          long long left = *min_element(sweetness.begin(),sweetness.end());
          long long sum = 0;
          sum = accumulate(sweetness.begin(),sweetness.end(),sum);
          long long right = sum;
          
          while(left<=right)
          {
              long long mid = left + (right-left)/2;
              long long x = 0,cnt=0;
              for(int i=0;i<n;i++)
              {
                 x += sweetness[i];
                 if(x>=mid)
                 {
                     cnt++;
                     x = 0;
                 }
              }
              if(cnt>=(k+1))
              {
                  left = mid+1;
              }
              else{
                  right = mid-1;
              }
              
          }
          return left-1;
    }
