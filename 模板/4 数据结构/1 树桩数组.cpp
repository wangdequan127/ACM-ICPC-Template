//一定要给N赋值，一定要清空数组
int N;
const int NV=100005;
int c[NV];
inline int lowbit(int t)
{
    return t&(-t);
}
void update(int x,int v)
{
    while(x<=N)
    {
        c[x]+=v;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int findkth(int k)
{
    int idx = 0;
    for(int i=20; i>=0; i--)
    {
        idx |= 1 << i;
        if(idx <= N && c[idx] < k)
            k -= c[idx];
        else idx ^= 1 << i;
    }
    return idx + 1;
}

/* 经典例题
A - 敌兵布阵
Time Limit:1000MS     Memory Limit:32768KB     64bit IO Format:%I64d & %I64u
Submit Status Practice HDU 1166
Description
C国的死对头A国这段时间正在进行军事演习，所以C国间谍头子Derek和他手下Tidy又开始忙乎了。A国在海岸线沿直线布置了N个工兵营地,Derek和Tidy的任务就是要监视这些工兵营地的活动情况。由于采取了某种先进的监测手段，所以每个工兵营地的人数C国都掌握的一清二楚,每个工兵营地的人数都有可能发生变动，可能增加或减少若干人手,但这些都逃不过C国的监视。
中央情报局要研究敌人究竟演习什么战术,所以Tidy要随时向Derek汇报某一段连续的工兵营地一共有多少人,例如Derek问:“Tidy,马上汇报第3个营地到第10个营地共有多少人!”Tidy就要马上开始计算这一段的总人数并汇报。但敌兵营地的人数经常变动，而Derek每次询问的段都不一样，所以Tidy不得不每次都一个一个营地的去数，很快就精疲力尽了，Derek对Tidy的计算速度越来越不满:"你个死肥仔，算得这么慢，我炒你鱿鱼!”Tidy想：“你自己来算算看，这可真是一项累人的工作!我恨不得你炒我鱿鱼呢!”无奈之下，Tidy只好打电话向计算机专家Windbreaker求救,Windbreaker说：“死肥仔，叫你平时做多点acm题和看多点算法书，现在尝到苦果了吧!”Tidy说："我知错了。。。"但Windbreaker已经挂掉电话了。Tidy很苦恼，这么算他真的会崩溃的，聪明的读者，你能写个程序帮他完成这项工作吗？不过如果你的程序效率不够高的话，Tidy还是会受到Derek的责骂的.

Input
第一行一个整数T，表示有T组数据。
每组数据第一行一个正整数N（N<=50000）,表示敌人有N个工兵营地，接下来有N个正整数,第i个正整数ai代表第i个工兵营地里开始时有ai个人（1<=ai<=50）。
接下来每行有一条命令，命令有4种形式：
(1) Add i j,i和j为正整数,表示第i个营地增加j个人（j不超过30）
(2)Sub i j ,i和j为正整数,表示第i个营地减少j个人（j不超过30）;
(3)Query i j ,i和j为正整数,i<=j，表示询问第i到第j个营地的总人数;
(4)End 表示结束，这条命令在每组数据最后出现;
每组数据最多有40000条命令

Output
对第i组数据,首先输出“Case i:”和回车,
对于每个Query询问，输出一个整数并回车,表示询问的段中的总人数,这个数保持在int以内。

Sample Input
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End

Sample Output
Case 1:
6
33
59

*/
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
#include<set>
#include<stack>
#include<vector>
#include<map>
#define pi acos(-1.0)
#define inf 1<<20
#define debug puts("**********");
#define mem(x) memset(x,0,sizeof(x))
typedef long long ll;
using namespace std;
const int mod = 1e9+7;
const int maxn= 100010;
ll ans = 0;
int a[maxn]= {0};
int temp[maxn]= {0};
void Merge(int l,int m,int r)
{
    int i=l,j=m+1,k=l;
    while(i<=m&&j<=r)
    {
        if(a[i]>a[j])
        {
            temp[k++]=a[j++];
            ans+=m-i+1;
            //printf("l=%d m=%d r=%d i=%d j=%d a[i]=%d a[j]=%d\n",l,m,r,i,j-1,a[i],a[j]);
        }
        else
        {
            temp[k++]=a[i++];
        }
    }
    while(i<=m)temp[k++]=a[i++];
    while(j<=r)temp[k++]=a[j++];
    for(i=l; i<=r; i++)
        a[i]=temp[i];
}
void Merge_sort(int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        Merge_sort(l,m);
        Merge_sort(m+1,r);
        Merge(l,m,r);
    }
}
int main()
{
    int T,I;
    scanf("%d",&T);
    for(I=1; I<=T; I++)
    {
        mem(a);
        mem(temp);
        ans=0;
        int n;
        scanf("%d",&n);
        int i;
        for(i=0; i<n; i++)
            scanf("%d",a+i);
        Merge_sort(0,n-1);
        printf("Scenario #%d:\n%I64d\n\n",I,ans);
    }

}

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
typedef long long ll;
using namespace std;
int n,num=1;
int c[50005];
int lowbit(int x)
{
    return x&(-x);
}
void  update(int i,  int x)
{
    while(i<=n)  {c[i] = c[i]+x; i += lowbit(i);}
}
int sum(int i)
{
    int  ans = 0;
    while(i>0) { ans += c[i]; i -= lowbit(i);}
    return ans;
}
int main()
{
    int t,i,j,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(c,0,sizeof(c));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&l);
            update(i,l);
        }
        printf("Case %d:\n",num++);
        char s[10];
        while(scanf("%s",s)!=EOF)
        {
            if(s[0]=='E')break;scanf("%d%d",&i,&j);
            switch(s[0])
            {
                case 'A':update(i,j);break;
                case 'S':update(i,-j);break;
                case 'Q':printf("%d\n",sum(j)-sum(i-1));break;
                default : printf("wrroy");
            }
        }
    }
    return 0;
}
二维：
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 505
int a[N][N];
int sum[N][N];
int n,m,q;
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int y,int k)
{
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            sum[i][j]^=k;
        }
    }
}
int query(int x,int y)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            ans^=sum[i][j];
        }
    }
    return ans;
}
int main()
{
    int T,x1,x2,y1,y2,k;
    scanf("%d",&T);
    while(T--){
        memset(sum,0,sizeof(sum));
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
                update(i,j,a[i][j]);
            }
        }
        while(q--){
            scanf("%d",&k);
            if(k==1){
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                int ans = 0;
               ans ^= query(x2, y2);
               if(y1 > 1) ans ^= query(x2, y1 - 1);
                if(x1 > 1) ans ^= query(x1 - 1, y2);
               if(x1 > 1 && y1 > 1) ans ^= query(x1 - 1, y1 - 1);
                if(ans == 0) {
                    printf("No\n");
                } else {
                    printf("Yes\n");
                }

            }
            else{
                scanf("%d%d%d",&x1,&y1,&x2);
                update(x1,y1,a[x1][y1]^x2);
                a[x1][y1]=x2;
            }
        }
    }
    return 0;
}
