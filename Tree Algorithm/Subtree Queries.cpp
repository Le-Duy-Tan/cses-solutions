#include <bits/stdc++.h>
using namespace std;
long long n,q,l,r,type,a[200005],flat[200005],in[200005],out[200005],sz=0,st[800005];
vector <long long> g[200005];
void dfs(long long u,long long parent)
{
    flat[++sz]=u;
    in[u]=sz;
    out[u]=sz;
    for (auto v:g[u])
    {
        if (v!=parent)
        {
            dfs(v,u);
            out[u]=sz;
        }
    }
}
void build(long long node,long long l,long long r)
{
    if (l==r)
    {
        st[node]=a[flat[l]];
        return;
    }
    long long mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    st[node]=st[node*2]+st[node*2+1];
}
void update(long long node,long long l,long long r,long long i,long long x)
{
    if (l==r)
    {
        a[flat[l]]=x;
        st[node]=x;
        return;
    }
    long long mid=(l+r)/2;
    if (i<=mid) update(node*2,l,mid,i,x);
    else update(node*2+1,mid+1,r,i,x);
    st[node]=st[node*2]+st[node*2+1];
}
long long get(long long node,long long l,long long r,long long u,long long v)
{
    if (r<u||l>v) return 0;
    if (l>=u&&r<=v) return st[node];
    long long mid=(l+r)/2;
    return get(node*2,l,mid,u,v)+get(node*2+1,mid+1,r,u,v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=2;i<=n;i++)
    {
        cin>>l>>r;
        g[l].push_back(r);
        g[r].push_back(l);
    }
    dfs(1,0);
    build(1,1,n);
    while (q--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>l>>r;
            update(1,1,n,in[l],r);
        }
        else
        {
            cin>>l;
            cout<<get(1,1,n,in[l],out[l])<<'\n';
        }
    }
    return 0;
}
