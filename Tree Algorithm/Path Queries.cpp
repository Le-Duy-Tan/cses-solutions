#include <bits/stdc++.h>
using namespace std;
long long n,q,l,r,type,a[200005],parent[200005],flat[200005],heavy[200005],st[800005],pos[200005],sz[200005],head[200005],cnt=0,res=0;
vector <long long> g[200005];
void dfssz(long long u)
{
    sz[u]++;
    for (auto v:g[u])
    {
        if (v!=parent[u])
        {
            parent[v]=u;
            dfssz(v);
            sz[u]+=sz[v];
        }
    }
}
void dfsheavy(long long u)
{
    long long weight=0;
    for (auto v:g[u])
    {
        if (v!=parent[u])
        {
            if (sz[v]>weight)
            {
                weight=sz[v];
                heavy[u]=v;
            }
            dfsheavy(v);
        }
    }
}
void dfshead(long long u,long long start)
{
    head[u]=start;
    pos[u]=++cnt;
    flat[cnt]=u;
    if (heavy[u]>0)
        dfshead(heavy[u],head[u]);
    for (auto v:g[u])
        if (v!=parent[u]&&v!=heavy[u])
            dfshead(v,v);
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
    dfssz(1);
    dfsheavy(1);
    dfshead(1,1);
    build(1,1,n);
    while (q--)
    {
        cin>>type;
        if (type==1)
        {
            cin>>l>>r;
            update(1,1,n,pos[l],r);
        }
        else
        {
            cin>>l; res=0;
            while (head[l]!=1)
            {
                res+=get(1,1,n,pos[head[l]],pos[l]);
                l=parent[head[l]];
            }
            res+=get(1,1,n,1,pos[l]);
            cout<<res<<'\n';
        }
    }
    return 0;
}
