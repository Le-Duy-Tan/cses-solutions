#include <bits/stdc++.h>
using namespace std;
long long n,q,parent[200005],up[20][200005],bit[20],a,b,depth[200005],jointpar;
vector <long long> g[200005];
void dfs(long long u,long long deep)
{
    depth[u]=deep;
    for (auto v:g[u])
    {
        if (v!=parent[u])
        {
            parent[v]=u;
            dfs(v,deep+1);
        }
    }
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
long long lca(long long u,long long v)
{
    if(depth[u]<depth[v])
        swap(u,v);
    u=lift(u,depth[u]-depth[v]);
    if (u==v) return u;
    for (int i=18;i>=0;i--)
    {
        if (up[i][u]!=up[i][v])
        {
            u=up[i][u];
            v=up[i][v];
        }
    }
    return parent[u];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for (int i=2;i<=n;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bit[0]=1; parent[1]=1;
    dfs(1,0);
    for (int i=1;i<=18;i++)
        bit[i]=bit[i-1]*2;
    for (int i=1;i<=n;i++)
        up[0][i]=parent[i];
    for (int i=1;i<=18;i++)
        for (int j=1;j<=n;j++)
            up[i][j]=up[i-1][up[i-1][j]];
    while (q--)
    {
        cin>>a>>b;
        jointpar=lca(a,b);
        cout<<depth[a]+depth[b]-2*depth[jointpar]<<'\n';
    }
    return 0;
}
