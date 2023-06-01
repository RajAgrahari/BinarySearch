//https://www.codechef.com/problems/DIVIDE_GROUP
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() 
{
    int t;
    cin>>t;
    while(t--)
    {
       int m;
        cin>>m;
        int n;
        cin>>n;
        vector<int> a(m);
        int mx=0;
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
            mx += a[i];
        }
        if(n>m){
            cout<<0<<endl;
            continue;
        }
        int l=1;
        int r=mx;
        r+=2;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int req=mid*n;
            for(int i=0;i<m;i++){
 
                req-=min(mid,a[i]);
                if(req<=0)
                break;
            }
            if(req<=0)
            l=mid+1;
            else 
            r=mid-1;
        }
        cout<<l-1<<"\n";
        
    }
	return 0;
}
