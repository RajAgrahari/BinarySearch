//https://codeforces.com/problemset/problem/706/B
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
    
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
        ll q;
        cin>>q;
        for(ll i=0;i<q;i++)
        {
            ll x;
            cin>>x;
            int y = upper_bound(a,a+n,x)-a;
            cout<<y<<'\n';
        }
    return 0;
}
