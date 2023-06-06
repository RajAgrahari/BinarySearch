//https://codeforces.com/contest/1840/problem/D
#include <bits/stdc++.h>
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
        vector<ll> a(n);
        for(ll i=0;i<n;i++)
        cin>>a[i];
        sort(a.begin(),a.end());
        ll l = 0,r = a[n-1]-a[0];
        while(l<=r)
        {
            ll mid = l + (r-l)/2;
            ll temp = a[0]+mid;
            ll cnt=1;
            for(ll i=0;i<n;i++)
            {
                if(a[i]-temp>mid)
                {
                   temp =  a[i] + mid;
                   cnt++;
                }
            }
            if(cnt>=4)
            l = mid+1;
            else
            r = mid-1;
            
        }
        cout<<l<<endl;
    }
    return 0;
}
