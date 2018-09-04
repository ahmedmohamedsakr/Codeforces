#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=5e2+4,M=1e3+5,OO=0x3f3f3f3f;
int n,m,k,r,c;
int vis[N][N];
char maze[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int r,int c){
 return (r<0||c<0||r>=n||c>=m||maze[r][c]=='#');
}

void dfs(int r,int c){
    if(valid(r,c))return;
    vis[r][c]=1;
    for(int i=0;i<4;++i){
        if(!vis[r+dx[i]][c+dy[i]])dfs(r+dx[i],c+dy[i]);
    }
    if(k>0){
        k--;
        maze[r][c]='X';
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
    for(int j=0;j<m;++j){
        cin>>maze[i][j];
        if(maze[i][j]=='.')r=i,c=j;
    }
    dfs(r,c);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)printf("%c",maze[i][j]);
        puts("");
    }
    return 0;
}
