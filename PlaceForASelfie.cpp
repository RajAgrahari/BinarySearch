//https://codeforces.com/contest/1805/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
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
int countTotalFactors(int n)//including 1 and n
{
    int count=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if((n%i)==0)
        {
            if((n/i)==i)
            count++;
            else
            count+=2;
        }
    }
    return count;
}
void countTotalPrimeFactors(int n)
{
    //if number is even then extract all 2 from it.
     while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        cout << n << " ";
}
ll get_pos(ll b,vector<ll>& k)
{
     auto it = lower_bound(k.begin(),k.end(),b);
     if(it==k.end())
     return (1LL)*k.size();
     return (1LL)*(it-k.begin());
}
ll get_res(ll l,ll r,ll b,ll ac,vector<ll>& k,ll n)
{
   ll res = LONG_MAX;
   for(ll x=l;x<=r && res==LONG_MAX;x++)
   {
       if(0<=x && x<n && 4*(ac)> (k[x]-b)*(k[x]-b))
       res = k[x];
   }
   return res;
}
int main()
{
NOOB CODER SOLUTION
    ll t;
    cin>>t;
    while(t--)
    {
       ll n,m;
       cin>>n>>m;
       vector<ll> k(n);
       for(int i=0;i<n;i++)
       cin>>k[i]; 
       sort(k.begin(),k.end());
       ll a[m][3];
       for(ll i=0;i<m;i++)
       {
          cin>>a[i][0]>>a[i][1]>>a[i][2];
       } 
      
               
                for(ll j=0;j<m;j++)
                {
                    ll ac = a[j][0]*a[j][2];
                    ll s = sqrt(ac);
                    ll x = get_pos(a[j][1]-s,k);
                    ll res = get_res(x-10,x+10,a[j][1],ac,k,n);
                    if(res!=LONG_MAX)
                    {
                        cout<<"YES\n"<<res<<endl;
                        continue;
                    }
                    x = get_pos(s-a[j][1],k);
                    res = get_res(x-10,x+10,a[j][1],ac,k,n);
                    if(res!=LONG_MAX)
                    {
                        cout<<"YES\n"<<res<<endl;
                        continue;
                    }
                    cout<<"NO\n";
                }
               

       cout<<endl;
    }
    return 0;
}
