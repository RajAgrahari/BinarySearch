//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAX 10000000
#define NOOB ios_base::sync_with_stdio(false);
#define CODER cin.tie(NULL);
#define SOLUTION cout.tie(NULL);
ll countSetBits(ll n)
{
    ll count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
ll bs_sqrt(ll x)
{
ll left = 0, right = 2000000123;
while (right > left)
{
ll mid = (left + right) / 2;
if (mid * mid > x) right = mid;
else left = mid + 1;
}
return left - 1;
}
ll power(ll N,ll R)
    {
       ll m = 1000000007;
       if(R==0) 
       return 1;
        ll ans=power(N,R/2);
        ans=(ans*ans)%m;
        if(R%2==0) 
        return ans;
        return ans*N%m; 
       
    }
// Sieve of Eratosthenes
vector<bool> IsPrime(ll n)
{
    vector<bool> prime(n,true);
    prime[0]=false;
    prime[1]=false;
    for(ll i=2;i*i<=n;i++)
    {
        if(prime[i])
        for(ll j=i*i;j<=n;j+=i)
        {
            prime[j]=false;
        }
    }
    return prime;
}
//Euclid's gcd
ll gcd(ll a,ll b)
{
    if(b == 0)
    return a;
    else
    return gcd(b, a%b);
}


int main()
{
    vector<ll> v(MAX+1,0);
    vector<ll> ans(MAX+1,0);
 
    ll prev=0;
    ll mi = sqrt(MAX);
    for(ll i=0;i<=mi;i++)
    {
        for(ll j=i;j<=mi;j++)
        {
            ll x = (i*i + j*j);
             if(MAX>=x)
             {
                ans[x] = 1;
             }
             else{
                 break;
             }
             
        }
    }
    for(int i=1;i<=MAX;i++)
    {
        if(ans[i]==0)
        ans[i] = ans[i-1];
        else
        ans[i] = ans[i-1]+1;
    }
    ll t;
    cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       ll l=0;
       ll r=n;
       while(l<=r)
       {
          ll mid = l+(r-l)/2;
          if(ans[mid]>0)
          l = mid+1;
          else
          r = mid-1;
       }
       cout<<ans[l-1]<<endl;
       
    }
    return 0;
}
