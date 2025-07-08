#include <bits/stdc++.h>
using namespace std;
long long n,a,b,dp[3][200005],parent[200005];
vector <long long> g[200005];
void dfs(long long u)
{
    for (auto v:g[u])
    {
        if(v!=parent[u])
        {
            parent[v]=u;
            dfs(v);
            dp[0][u]+=dp[1][v];
        }
    }
    for (auto v:g[u])
        if (v!=parent[u])
            dp[1][u]=max(dp[1][u],dp[0][u]-dp[1][v]+dp[0][v]+1);
}
int main()
{
    if (fopen("DONGXU.INP","r"))
    {
        freopen("DONGXU.INP","r",stdin);
        freopen("DONGXU.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    cout<<max(dp[1][1],dp[0][1]);
    return 0;
}
