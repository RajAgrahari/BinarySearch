//https://codeforces.com/contest/357/problem/C
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
    ll n,m;
    cin>>n>>m;
    set<ll> alive;
    vector<ll> ans(n,0);
    for (ll i = 0; i < n; i++)
        alive.insert(i);
        
    for (ll i = 0; i < m; i++) 
    {
        ll l, r, x;
        cin>>l>>r>>x;
        l--, r--;        
        auto it = alive.lower_bound(l);
        vector<ll> toErase;        
        while(it != alive.end())
        {
            ll cur = *it;            
            if(cur > r)
                break;                
            if(cur != x-1){    
                toErase.push_back(cur); 
                ans[cur] = x;
            }
            it++;
        }

        for (ll j = 0; j < toErase.size(); j++)
            alive.erase(toErase[j]);
    }
    for(ll i=0;i<n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
