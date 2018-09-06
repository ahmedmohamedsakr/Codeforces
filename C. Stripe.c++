#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+4,M=2e2+4,OO=0x3f3f3f3f;
int n,cnt;
int cum[N],a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        cum[i]=cum[i-1]+a[i];
    }
    for(int i=2;i<=n;++i){
        if(cum[n]-cum[i-1]==cum[i-1])cnt++;
    }
    printf("%d",cnt);
    return 0;
}
