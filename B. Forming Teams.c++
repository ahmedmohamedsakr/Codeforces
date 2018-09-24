#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e2+5,M=1e6+5,OO=0x3f3f3f3f;

int size[N],par[N];
int n,m,u,v,odcycle;

void init()
{
    for(int i=1; i<=n; ++i)par[i]=i,size[i]=1;
}

int find(int u)
{
    return (par[u]==u?u:par[u]=find(par[u]));
}
bool join(int a,int b)
{
    a=find(a),b=find(b);
    if(a==b)return 0;
    par[b]=a;
    size[a]+=size[b];
    return 1;
}
int main ()
{
    scanf("%d%d",&n,&m);
    init();
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d",&u,&v);
        if(!join(u,v))
            if(size[find(u)]&1)odcycle++;
    }
    if((n-odcycle)&1)odcycle++;
    printf("%d",odcycle);
    return 0;
}
