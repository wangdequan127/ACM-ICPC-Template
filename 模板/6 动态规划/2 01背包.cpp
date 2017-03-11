#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int bag[2000];
    int w[2000],h[2000];
    int n,m;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
          memset(bag,0,sizeof(bag));
    for(int i=0;i<n;i++)
        scanf("%d",&h[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&w[i]);
    for(int i=0;i<n;i++)
        for(int k=m;k>=w[i];k--)//k代表能容下k kg的背包
        bag[k]=max(bag[k-w[i]]+h[i],bag[k]);
    printf("%d\n",bag[m]);
    }
    return 0;
}
#include<iostream>
#include<stdio.h>
#include<queue>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include<vector>
#include<map>
#define pi acos(-1.0)
#define inf 1<<29
typedef long long ll;
using namespace std;
int main()
{
     int bag[2000];
    int w[2000],j[2000];
    int n,m;
    int t;
        scanf("%d%d",&m,&n);
          memset(bag,0,sizeof(bag));
    for(int i=0;i<n;i++)
        scanf("%d%d",&w[i],&j[i]);
    for(int i=0;i<n;i++)
        for(int k=m;k>=w[i];k--)//k代表能容下k kg的背包
        bag[k]=max(bag[k-w[i]]+j[i],bag[k]);
    printf("%d",bag[m]);
    return 0;
}

/*
J - FATE
Time Limit:1000MS     Memory Limit:32768KB     64bit IO Format:%I64d & %I64u
Submit Status Practice HDU 2159
Description
最近xhd正在玩一款叫做FATE的游戏，为了得到极品装备，xhd在不停的杀怪做任务。久而久之xhd开始对杀怪产生的厌恶感，但又不得不通过杀怪来升完这最后一级。现在的问题是，xhd升掉最后一级还需n的经验值，xhd还留有m的忍耐度，每杀一个怪xhd会得到相应的经验，并减掉相应的忍耐度。当忍耐度降到0或者0以下时，xhd就不会玩这游戏。xhd还说了他最多只杀s只怪。请问他能升掉这最后一级吗？

Input
输入数据有多组，对于每组数据第一行输入n，m，k，s(0 < n,m,k,s < 100)四个正整数。分别表示还需的经验值，保留的忍耐度，怪的种数和最多的杀怪数。接下来输入k行数据。每行数据输入两个正整数a，b(0 < a,b < 20)；分别表示杀掉一只这种怪xhd会得到的经验值和会减掉的忍耐度。(每种怪都有无数个)

Output
输出升完这级还能保留的最大忍耐度，如果无法升完这级输出-1。

Sample Input
10 10 1 10
1 1
10 10 1 9
1 1
9 10 2 10
1 1
2 2

Sample Output
0
-1
1

*/
//二维背包
#include<stdio.h>
#include<string.h>
int dp[101][101];      //dp[i][j] 表示消耗i的忍耐度和杀j个怪物得到的最大经验值
struct node
{
    int e;     //经验值
    int r;     //忍耐度
}a[101];

int main()
{
    int n,m,k,s,i,j,t;
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)
    {
        for(i=1;i<=k;++i)
            scanf("%d%d",&a[i].e,&a[i].r);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=k;++i)   //k表示怪物种类---对不同怪物遍历一遍
            for(j=a[i].r;j<=m;++j)  //m表示保留的忍耐度
                for(t=1;t<=s;++t)    // s表示杀的怪物数
                {
                    if(dp[j][t]<dp[j-a[i].r][t-1]+a[i].e)
                    {
                        dp[j][t]=dp[j-a[i].r][t-1]+a[i].e;
                    }
                }
        if(dp[m][s]>=n)     //表示能过升级
        {
                for(i=0;i<=m;++i)   //寻找能够升级所消耗的最小忍耐度,只用找消耗相同忍耐度的情况下，令杀怪数量最多，
                    if(dp[i][s]>=n) //那么d[i][s]一定是消耗i忍耐度的情况下，获得的最大经验值
                    {
                        printf("%d\n",m-i);
                        break;
                    }
        }
        else
            printf("-1\n");
    }
    return 0;
}
//自己的代码
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include<vector>
#include<map>
#define pi acos(-1.0)
#define inf 1<<29
#define bug puts("**********");
#define mx 1010
typedef long long ll;
using namespace std;
#define mod 1000000009
int main()
{
    int n,m,k,s;
    int dp[110][110],st[110],e[110];
    while(~scanf("%d%d%d%d",&n,&m,&k,&s))
    {
        memset(dp,0,sizeof(dp));
        memset(st,0,sizeof(st));
        memset(e,0,sizeof(e));
        int i,j,l;
        for(i=0;i<k;i++)
            scanf("%d%d",&e[i],&st[i]);
        for(i=0;i<k;i++)
            for(j=st[i];j<=m;j++)
            for(l=1;l<=s;l++)
            if(dp[j][l]<dp[j-st[i]][l-1]+e[i])
            dp[j][l]=dp[j-st[i]][l-1]+e[i];
        if(dp[m][s]>=n)
        {
            for(i=0;i<=m;i++)
                if(dp[i][s]>=n)
            {
                printf("%d\n",m-i);
                break;
            }
        }
        else
            printf("-1\n");
    }
    return 0;
}

