//https://codeforces.com/contest/1795/problem/C
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
        ll a[n];
        for(ll i=0;i<n;i++)
        cin>>a[i];
        ll b[n];
        vector<ll> pre(n+1,0);
        pre[0] =0;
        for(ll i=0;i<n;i++)
        {
            cin>>b[i];
            pre[i+1] = pre[i] + b[i];
        }
        // for(ll x:pre)
        // cout<<x<<' ';
        // cout<<'\n';
        vector<ll> ans(n+2,0);
        vector<ll> res(n+2,0);
        for(ll i=0;i<n;i++)
        {
            ll idx = lower_bound(pre.begin(),pre.end(),a[i]+pre[i])-pre.begin();
            
            ans[i] -= 1;
            if(idx==n+1)
            {
                ans[n] += 1;
                continue;
            }
            ans[idx-1] += 1;
            res[idx] +=(a[i]+pre[i]-pre[idx-1]);
           
        }
        for (int i = n - 1; i >= 0; --i) 
        {
		    ans[i] += ans[i + 1];
	    }
        for(ll i=1;i<=n;i++)
        cout<<(ans[i]*b[i-1] + res[i])<<' ';
        cout<<'\n';


    }
    return 0;
}
