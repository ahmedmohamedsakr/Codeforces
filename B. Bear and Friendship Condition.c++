#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5,M=1e6+5,OO=0x3f3f3f3f;
int n,m,u,v,vis[N];
vector<int>adj[N];
ll num_vertices,num_edges;
void dfs(int src)
{
    vis[src]=1;
    num_vertices++;                    //count number of vertices.
    num_edges+=adj[src].size();        //count number of edges by (Handshaking Lemma).
    for(auto it:adj[src])if(!vis[it])dfs(it);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; ++i)
    {
        num_vertices=num_edges=0;
        if(!vis[i])
        {
            dfs(i);
            if(num_edges/*>>1*/!=(num_vertices*(num_vertices-1))/*>>1*/)return puts("NO"),0;
        }
    }
    puts("YES");
    return 0;
}
