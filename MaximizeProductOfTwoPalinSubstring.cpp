//https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/
long long maxProduct(string s) 
    {
         int n = s.size();
         vector<int> p(n);
         int center=0,right=0,longest=0,longestIdx=0;
         for(int i=0;i<n;i++)
         {
             int mirror = (center-(i-center));
             if(right>i)
             p[i] = min(p[mirror],right-i);

             int l = i - (p[i]+1);
             int r = i + (p[i]+1);

             while(l>=0 && r<s.size() && s[l]==s[r])
             {
                 l--;
                 r++;
                 p[i]++;
             }
             if(p[i]>longest)
             {
                 longestIdx = i;
                 longest = p[i];
             }
             if(i+p[i]>right)
             {
                 right = p[i]+i;
                 center = i;
             }
         }
         vector<int> left(n,0);
         left[0] = 1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=1;i<=n-1;i++)
        {
            if(p[i]>0)
                pq.push({i,p[i]}),left[i]=1;
            if(!pq.empty())
            {
                while(!pq.empty() && pq.top().first+pq.top().second<i)
                    pq.pop();
                if(!pq.empty())
                    left[i]= 2*(i-pq.top().first)+1;
                else
                    left[i]=1;
            }
            left[i]=max(left[i],left[i-1]);
        }
		
		// Finding the longest palindrome ending after ith index or at ith index 
        priority_queue<pair<int,int>> pql;
        int m=1,l=1;
        long long ans=0;
        ans = max(ans,1LL*left[n-2]*m);
        for(int i=n-2;i>=0;i--)
        {
            if(p[i]>0)
            pql.push({i,p[i]}),l=1;
            if(!pql.empty())
            {
                while(!pql.empty() && pql.top().first-pql.top().second>i)
                    pql.pop();
                if(!pql.empty())
                    l= 2*(pql.top().first-i)+1;
                else
                    l=1;
            }
            m=max(m,l);
            if(i>0)
                ans= max(ans, 1LL*left[i-1]*m);
        }
        return ans;
         
    }
