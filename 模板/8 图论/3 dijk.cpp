dijk
#include<bits/stdc++.h>
using namespace std;
#define INF 1<<29
#define debug puts("**********\n")
#define mx 1005
int mapp[mx][mx];
int dis[mx],mark[mx];
void init()
{
    int i,j;
    for(i=0;i<mx;i++)
        for(j=0;j<mx;j++)
        mapp[i][j]=INF;
    memset(mark,0,sizeof(0));
}
void dijk(int u,int n)
{
    int m,i,j,min,v;
    memset(mark,0,mx);
    for(i=1;i<=n;i++)
        dis[i]=mapp[u][i];
    mark[u]=1;
    dis[u]=0;
    while(1)
    {
        min=INF;
        for(i=1;i<=n;i++)
            if(!mark[i]&&min>dis[i])
            min=dis[i],v=i;
        if(min==INF)
            break;
        mark[v]=1;
        for(i=1;i<=n;i++)
            if(!mark[i]&&dis[v]+mapp[v][i]<dis[i])
            dis[i]=dis[v]+mapp[v][i];
    }
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int i,j,a,b,c;
        init();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            mapp[a][b]=mapp[b][a]=c;
        }
        dijk(1,n);
        printf("%d\n",dis[n]);
    }
}


