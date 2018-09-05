#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e2+4,M=1e3,OO=0x3f3f3f3f;
int n,b,odd,even,cnt;
int a[N];
vector<int>v;
int main()
{

    scanf("%d%d",&n,&b);
    for(int i=0; i<n; ++i)scanf("%d",a+i);
    for(int i=0; i<n; ++i)
    {
        (a[i]&1)?odd++:even++;
        if(odd==even&&i!=n-1)v.push_back(abs(a[i+1]-a[i]));
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size()&&v[i]<=b; ++i)b-=v[i],cnt++;
    printf("%d",cnt);
    return 0;
}
