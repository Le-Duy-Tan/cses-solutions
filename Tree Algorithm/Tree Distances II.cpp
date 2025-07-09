#include <bits/stdc++.h>
using namespace std;
long long n,a,b,dist1[200005],dp[200005],subtree[200005];
vector <long long> g[200005];
void dfs(long long u,long long parent,long long dist)
{
    dist1[u]=dist;
    for (auto v:g[u])
    {
        if(v!=parent)
        {
            dfs(v,u,dist+1);
            subtree[u]+=subtree[v]+1;
        }
    }
}
void bfs(long long x)
{
    queue<pair<long long,long long>> q;
    q.push({x,0});
    while (!q.empty())
    {
        auto [u,parent]=q.front();
        q.pop();
        for (auto v:g[u])
        {
            if (v!=parent)
            {
                dp[v]=dp[u]-2*(subtree[v]+1)+n;
                q.push({v,u});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    for (int i=2;i<=n;i++)
        dp[1]+=dist1[i];
    bfs(1);
    for (int i=1;i<=n;i++)
        cout<<dp[i]<<" ";
    return 0;
}
