typedef int mytype;
const int NV=1005;
int pre[NV],vis[NV];
mytype dis[NV],g[NV][NV];
void init(int n,int m,int s)
{
    memset(pre,0,sizeof(pre));
    memset(vis,0,sizeof(vis));
    for (int i=0; i<=n; i++)
        dis[i]=inf;
    dis[s]=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            g[i][j]=inf;
    for (int i=1; i<=m; i++)
    {
        int u,v,l;
        scanf("%d%d%d",&u,&v,&l);
        g[u][v]=l;
        g[v][u]=l;
    }
}
mytype prim(int n)
{
    mytype ans=0;
    for (int i=1; i<=n; i++)
    {
        int u=0;
        for (int j=1; j<=n; j++)
            if (!vis[j]&&dis[j]<dis[u])
                u=j;
        vis[u]=1;
        ans+=dis[u];
        for (int j=1; j<=n; j++)
            if (!vis[j]&&g[u][j]<dis[j])
            {
                dis[j]=g[u][j];
                pre[j]=u;
            }
    }
    return ans;
}
bool judge(int n)
{
    int cnt=0;
    for (int i=1; i<=n; i++)
        cnt+=vis[i];
    return cnt==n;
}




typedef int mytype;
const int NV=105;
const int NE=10005;
struct edge
{
    int u,v;
    mytype l;
    bool operator<(const edge e) const
    {
        return l<e.l;
    }
} E[NE];
int f[NV],rk[NV];
int finds(int x)
{
    return f[x]==x?x:f[x]=finds(f[x]);
}
void uni(int a,int b)
{
    a=finds(a);
    b=finds(b);
    if (a==b) return;
    if (rk[a]>rk[b]) f[b]=a;
    else
    {
        if (rk[a]==rk[b]) rk[b]++;
        f[a]=b;
    }
}
void init(int n,int m)
{
    memset(rk,0,sizeof(rk));
    for (int i=1; i<=n; i++)
        f[i]=i;
    for (int i=1; i<=m; i++)
        scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].l);
}
mytype kruskal(int n,int m)
{
    sort(E+1,E+m+1);
    mytype ans=0;
    for (int i=1; i<=m; i++)
        if (finds(E[i].u)!=finds(E[i].v))
        {
            uni(E[i].u,E[i].v);
            ans+=E[i].l;
        }
    return ans;
}
bool judge(int n)
{
    int flag=0;
    for (int i=1; i<=n; i++)
        if (finds(i)==i)
            flag++;
    return flag==1;
}

