#include <bits/stdc++.h>
using namespace std;
long long n,q,parent[200005],up[20][200005],bit[20],a,b,depth[200005];
vector <long long> g[200005];
void dfs(long long u,long long parent,long long deep)
{
    depth[u]=deep;
    for (auto v:g[u])
        if (v!=parent)
            dfs(v,u,deep+1);
}
long long lift(long long u,long long dist)
{
    for (int i=18;i>=0;i--)
    {
        if (bit[i]<=dist)
        {
            u=up[i][u];
            dist-=bit[i];
        }
    }
    return u;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for (int i=2;i<=n;i++)
    {
        cin>>parent[i];
        g[parent[i]].push_back(i);
    }
    bit[0]=1; parent[1]=1;
    for (int i=1;i<=18;i++)
        bit[i]=bit[i-1]*2;
    for (int i=1;i<=n;i++)
        up[0][i]=parent[i];
    for (int i=1;i<=18;i++)
        for (int j=1;j<=n;j++)
            up[i][j]=up[i-1][up[i-1][j]];
    dfs(1,0,0);
    while (q--)
    {
        cin>>a>>b;
        if (depth[a]<b) cout<<-1<<'\n';
        else cout<<lift(a,b)<<'\n';
    }
    return 0;
}
