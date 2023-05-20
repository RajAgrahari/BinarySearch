//https://codeforces.com/contest/1826/problem/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define NOOB ios_base::sync_with_stdio(false);
#define CODER cin.tie(NULL);
#define SOLUTION cout.tie(NULL);

int main()
{
    NOOB CODER SOLUTION
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++)
        cin>>a[i];
        if(n==1)
        {
            if(a[0]==0)
            cout<<a[0]<<'\n';
            else
            cout<<-1<<'\n';
            continue;
        }
        sort(a,a+n);
       
        int in=-1;
        for(int i=0;i<=n;i++)
        {
           int idx = lower_bound(a,a+n,i)-a;
           if(idx==n)
           break;
           if(i==a[idx])
           {
               while(idx+1<n && a[idx]==a[idx+1])
               idx++;
               if((n-(idx+1)) == i)
               {
                  in = i;
                  break;
               }
           }
           else{
               if((n-idx) == i)
               {
                  in=i;
                  break;
               }
           }
        }
        cout<<in<<endl;
        
        
       
    }
    return 0;
}
