#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e9+5,OO=0x3f3f3f3f;

int n,m,a[N],b[N];

ll get(int x)
{
    ll sum=0;
    for(int i=0; i<n; ++i)if(a[i]<x)sum+=x-a[i];
    for(int i=0; i<m; ++i)if(b[i]>x)sum+=b[i]-x;
    return sum;
}

ll ternary_search()
{
    ll lo=0,hi=M,m1,m2,one,two,ans=1e18;
    while(lo<hi)
    {
        m1=lo+(hi-lo)/3;
        m2=hi-(hi-lo)/3;
        one=get(m1);
        two=get(m2);
        ans=min(ans,min(one,two));
        (one>two)?lo=m1+1:hi=m2-1;
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; ++i)scanf("%d",a+i);
    for(int i=0; i<m; ++i)scanf("%d",b+i);
    printf("%lld",ternary_search());
    return 0;
}
