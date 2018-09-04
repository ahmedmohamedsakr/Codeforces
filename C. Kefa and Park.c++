#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+4,M=1e3+5,OO=0x3f3f3f3f;
int n,m,u,v,cnt;
int c[N],vis[N];
vector<int>adj[N];
void dfs(int src=1,int cat=0){
   vis[src]=1;
   if(c[src])cat++;
   else cat=0;
   if(cat>m)return;
   for(auto it:adj[src])if(!vis[it])dfs(it,cat);

   if(adj[src].size()==1&&src!=1)cnt++;
}
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;++i)scanf("%d",c+i);
   for(int i=1;i<n;++i){
    scanf("%d%d",&u,&v);
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   dfs();
   printf("%d",cnt);
    return 0;
}
