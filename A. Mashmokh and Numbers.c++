#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=5e5+5,M=1e9+5,OO=0x3f3f3f3f;
int n,k,q;
int main()
{
    scanf("%d%d",&n,&k);
    if(k<n/2||(n==1&&k))return printf("-1"),0;
    q=k-((n-2)>>1);
    if(k==n/2){
     for(int i=1;i<=n;++i)printf("%d ",i);
    }else{
    n-=2;
    printf("%d %d",q,q<<1);
    q<<=1;
    for(int i=0;i<n;++i)printf(" %d",++q);
    }
    return 0;
}
