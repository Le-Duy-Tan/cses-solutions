#include <bits/stdc++.h>
using namespace std;
long long n,subtree[200005],a;
vector <long long> g[200005];
void dfs(long long x)
{
    if (g[x].size()==0) return;
    for (auto i:g[x])
    {
        dfs(i);
        subtree[x]+=subtree[i]+1;
    }
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
        cin>>a;
        g[a].push_back(i);
    }
    dfs(1);
    for (int i=1;i<=n;i++) cout<<subtree[i]<<" ";
    return 0;
}
