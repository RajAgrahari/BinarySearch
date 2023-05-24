//https://codeforces.com/problemset/problem/1794/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define NOOB ios_base::sync_with_stdio(false);
#define CODER cin.tie(NULL);
#define SOLUTION cout.tie(NULL);
ll fact(ll n)
{
     if(n==0 || n==1)
     return 1;
     return (fact(n-1)*n);
}
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
        {
            cin>>a[i];
        }
        vector<ll> ans;
        for(ll i=0;i<n;i++)
        {
            ll l=0,r=i;
            while(l<=r)
            {
               ll mid = l+(r-l)/2;
               if(a[mid] < (i-mid+1))
               l = mid+1;
               else
               r = mid-1;
            }
            ans.push_back(i-l+1);
        }
        for(ll x:ans)
        cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}
