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
        for(int k=m;k>=w[i];k--)//k����������k kg�ı���
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
        for(int k=m;k>=w[i];k--)//k����������k kg�ı���
        bag[k]=max(bag[k-w[i]]+j[i],bag[k]);
    printf("%d",bag[m]);
    return 0;
}

/*
J - FATE
Time Limit:1000MS     Memory Limit:32768KB     64bit IO Format:%I64d & %I64u
Submit Status Practice HDU 2159
Description
���xhd������һ�����FATE����Ϸ��Ϊ�˵õ���Ʒװ����xhd�ڲ�ͣ��ɱ�������񡣾ö���֮xhd��ʼ��ɱ�ֲ��������У����ֲ��ò�ͨ��ɱ�������������һ�������ڵ������ǣ�xhd�������һ������n�ľ���ֵ��xhd������m�����Ͷȣ�ÿɱһ����xhd��õ���Ӧ�ľ��飬��������Ӧ�����Ͷȡ������ͶȽ���0����0����ʱ��xhd�Ͳ���������Ϸ��xhd��˵�������ֻɱsֻ�֡������������������һ����

Input
���������ж��飬����ÿ�����ݵ�һ������n��m��k��s(0 < n,m,k,s < 100)�ĸ����������ֱ��ʾ����ľ���ֵ�����������Ͷȣ��ֵ�����������ɱ����������������k�����ݡ�ÿ��������������������a��b(0 < a,b < 20)���ֱ��ʾɱ��һֻ���ֹ�xhd��õ��ľ���ֵ�ͻ���������Ͷȡ�(ÿ�ֶֹ���������)

Output
��������⼶���ܱ�����������Ͷȣ�����޷������⼶���-1��

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
//��ά����
#include<stdio.h>
#include<string.h>
int dp[101][101];      //dp[i][j] ��ʾ����i�����ͶȺ�ɱj������õ��������ֵ
struct node
{
    int e;     //����ֵ
    int r;     //���Ͷ�
}a[101];

int main()
{
    int n,m,k,s,i,j,t;
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)
    {
        for(i=1;i<=k;++i)
            scanf("%d%d",&a[i].e,&a[i].r);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=k;++i)   //k��ʾ��������---�Բ�ͬ�������һ��
            for(j=a[i].r;j<=m;++j)  //m��ʾ���������Ͷ�
                for(t=1;t<=s;++t)    // s��ʾɱ�Ĺ�����
                {
                    if(dp[j][t]<dp[j-a[i].r][t-1]+a[i].e)
                    {
                        dp[j][t]=dp[j-a[i].r][t-1]+a[i].e;
                    }
                }
        if(dp[m][s]>=n)     //��ʾ�ܹ�����
        {
                for(i=0;i<=m;++i)   //Ѱ���ܹ����������ĵ���С���Ͷ�,ֻ����������ͬ���Ͷȵ�����£���ɱ��������࣬
                    if(dp[i][s]>=n) //��ôd[i][s]һ��������i���Ͷȵ�����£���õ������ֵ
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
//�Լ��Ĵ���
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

