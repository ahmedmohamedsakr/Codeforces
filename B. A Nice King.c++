#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+4,M=1e3+5,OO=0x3f3f3f3f;
int n,m,u,v,cnt;
int par[N];
vector<int>adj[N];

int find(int u)
{
    return (par[u]==u)?u:par[u]=find(par[u]);
}

void join(int a,int b)
{
    a=find(a),b=find(b);
    if(a==b)return;
    par[b]=a;
}
bool sameset(int a,int b)
{
    return find(a)==find(b);
}
void init()
{
    iota(par,par+N,0);
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d",&u,&v);
        if(!sameset(u,v))
        {
            join(u,v);
            cnt++;
        }
    }
    printf("%d",n-cnt-1);
    return 0;
}
