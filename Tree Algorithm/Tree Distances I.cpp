#include <bits/stdc++.h>
using namespace std;
long long n,a,b,maxdist=-1,farnode,damt1,damt2,itodamt1[200005],itodamt2[200005];
vector <long long> g[200005];
void dfs(long long u,long long parent,long long dist)
{
    if (dist>maxdist)
    {
        maxdist=dist;
        farnode=u;
    }
    for (auto v:g[u])
        if(v!=parent)
            dfs(v,u,dist+1);
}
void dfs1(long long u,long long parent,long long dist)
{
    itodamt1[u]=dist;
    for (auto v:g[u])
        if(v!=parent)
            dfs1(v,u,dist+1);
}
void dfs2(long long u,long long parent,long long dist)
{
    itodamt2[u]=dist;
    for (auto v:g[u])
        if(v!=parent)
            dfs2(v,u,dist+1);
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
    maxdist=-1;
    damt1=farnode;
    dfs(farnode,0,0);
    damt2=farnode;
    dfs1(damt1,0,0);
    dfs2(damt2,0,0);
    for (int i=1;i<=n;i++)
        cout<<max(itodamt1[i],itodamt2[i])<<" ";
    return 0;
}
