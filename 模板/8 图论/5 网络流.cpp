网络流（最大流）
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define inf 0x3f3f3f3f
#define debug puts("-----")
#define maxn 10000+5
#define ll long long
#define LL long long
#define NE 3000
#define mx 10005
#define ep 1e-2
#define pi acos(-1.0)
#define mod 1000000007
///===================================////
#define INF 0x3f3f3f3f
const int maxm = 120900;
int n;
struct Node {
    int v;    // vertex
    int cap;    // capacity
    int flow;   // current flow in this arc
    int nxt;
} e[maxm * 2];
int g[maxn], fcnt;
int st, ed;
void add_(int u, int v, int c) {
    e[++fcnt].v = v;
    e[fcnt].cap = c;
    e[fcnt].flow = 0;
    e[fcnt].nxt = g[u];
    g[u] = fcnt;
    e[++fcnt].v = u;
    e[fcnt].cap = 0;
    e[fcnt].flow = 0;
    e[fcnt].nxt = g[v];
    g[v] = fcnt;
}
void init_maxflow(int src,int sink,int n_) {
    memset(g, 0, sizeof(g));
    fcnt = 1;
n=n_;    //n为包括源点和汇点的总点个数
    st = src, ed = sink;/*修改*/
    //n = n + 3; //这里可以将n适当扩大一些
/*什么JB玩意儿*/
}
int dist[maxn], numbs[maxn], q[maxn];
void rev_bfs() {
    int font = 0, rear = 1;
    for (int i = 0; i <= n; i++) { //n为总点数
        dist[i] = maxn;
        numbs[i] = 0;
    }
    q[font] = ed;
    dist[ed] = 0;
    numbs[0] = 1;
    while(font != rear) {
        int u = q[font++];
        for (int i = g[u]; i; i = e[i].nxt) {
            if (e[i ^ 1].cap == 0 || dist[e[i].v] < maxn) continue;
            dist[e[i].v] = dist[u] + 1;
            ++numbs[dist[e[i].v]];
            q[rear++] = e[i].v;
        }
    }
}
int maxflow() {
    rev_bfs();
    int u, totalflow = 0;
    int curg[maxn], revpath[maxn];
    for(int i = 0; i <= n; ++i) curg[i] = g[i];
    u = st;
    while(dist[st] < n) {
        if(u == ed) {   // find an augmenting path
            int augflow = INF;
            for(int i = st; i != ed; i = e[curg[i]].v)
                augflow = min(augflow, e[curg[i]].cap);
            for(int i = st; i != ed; i = e[curg[i]].v) {
                e[curg[i]].cap -= augflow;
                e[curg[i] ^ 1].cap += augflow;
                e[curg[i]].flow += augflow;
                e[curg[i] ^ 1].flow -= augflow;
            }
            totalflow += augflow;
            u = st;
        }
        int i;
        for(i = curg[u]; i; i = e[i].nxt)
            if(e[i].cap > 0 && dist[u] == dist[e[i].v] + 1) break;
        if(i) {   // find an admissible arc, then Advance
            curg[u] = i;
            revpath[e[i].v] = i ^ 1;
            u = e[i].v;
        } else {    // no admissible arc, then relabel this vertex
            if(0 == (--numbs[dist[u]])) break;    // GAP cut, Important!
            curg[u] = g[u];
            int mindist = n;
            for(int j = g[u]; j; j = e[j].nxt)
                if(e[j].cap > 0) mindist = min(mindist, dist[e[j].v]);
            dist[u] = mindist + 1;
            ++numbs[dist[u]];
            if(u != st)
                u = e[revpath[u]].v;    // Backtrack
        }
    }
    return totalflow;
}
///================分割线=============///
//最大流的输出路径
int out[maxm][3], tot = 0;
void get_out() {
    for (int u = 1; u < ed; u++) {
        for (int i = g[u]; i; i = e[i].nxt) {
            if (e[i].v != ed && e[i].flow > 0) {
                out[tot][0] = u;
                out[tot][1] = e[i].v;
                out[tot++][2] = e[i].flow;
            }
        }
    }
}

//n为包括源点和汇点的总点个数

网络流（最小费用最大流）

#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define inf (1<<30)
using namespace std;
int st,en;
struct Edge
{
    int u,v,w,next;
    int cost;
}e[50000];
int ecnt,pre[250];
void adde(int u,int v,int w,int cost)
{
    e[ecnt].u=u;
    e[ecnt].v=v;
    e[ecnt].w=w;
    e[ecnt].cost=cost;
    e[ecnt].next=pre[u];
    pre[u]=ecnt++;
    e[ecnt].u=v;
    e[ecnt].v=u;
    e[ecnt].w=0;
    e[ecnt].cost=-cost;
    e[ecnt].next=pre[v];
    pre[v]=ecnt++;
}
int f,v;
void init()
{
    ecnt=0;
    memset(pre,-1,sizeof(pre));
    st=0,en=f+v+1;
}
bool vis[250];
int p[250];
int dis[250];
bool spfa()
{
    queue<int>que;
    memset(p,-1,sizeof(p));
    memset(vis,0,sizeof(vis));
    for(int i=st; i<=en; i++)
    {
        dis[i]=inf;
    }
    dis[st]=0;
    vis[st]=1;
    que.push(st);
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        vis[u]=0;
        for(int i=pre[u]; i!=-1; i=e[i].next)
        {
            int v=e[i].v;
            if(e[i].w>0&&dis[v]>dis[u]+e[i].cost)
            {
                dis[v]=dis[u]+e[i].cost;
                p[v]=i;
                if(vis[v]==0)
                {
                    que.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    if(dis[en]==inf)
        return false;
    return true;
}
int MCMF()
{
    int flow=0,mincost=0;
    int minflow;
    while(spfa())
    {
        minflow=inf;
        for(int i=p[en]; i!=-1; i=p[e[i].u])
        {
            minflow=min(minflow,e[i].w);
        }
        for(int i=p[en]; i!=-1; i=p[e[i].u])
        {
            e[i].w-=minflow;
            e[i^1].w+=minflow;
        }
        flow+=minflow;
        mincost+=minflow*dis[en];
    }
    return mincost;
}
int main()
{
    cin>>f>>v;
    init();
    int a;
    for(int i=1; i<=f; i++)
    {
        for(int j=1; j<=v; j++)
        {
            scanf("%d",&a);
            adde(i,f+j,1,-a);
        }
    }
    for(int i=1; i<=f; i++)
    {
        adde(st,i,1,0);
    }
    for(int i=1; i<=v; i++)
    {
        adde(f+i,en,1,0);
    }
    int ans=MCMF();
    cout<<-ans;
    return 0;
}

注意其中的ecnt必须从0开始

