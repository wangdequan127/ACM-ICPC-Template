//һ��Ҫ��N��ֵ��һ��Ҫ�������
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

/* ��������
A - �б�����
Time Limit:1000MS     Memory Limit:32768KB     64bit IO Format:%I64d & %I64u
Submit Status Practice HDU 1166
Description
C��������ͷA�����ʱ�����ڽ��о�����ϰ������C�����ͷ��Derek��������Tidy�ֿ�ʼæ���ˡ�A���ں�������ֱ�߲�����N������Ӫ��,Derek��Tidy���������Ҫ������Щ����Ӫ�صĻ��������ڲ�ȡ��ĳ���Ƚ��ļ���ֶΣ�����ÿ������Ӫ�ص�����C�������յ�һ�����,ÿ������Ӫ�ص��������п��ܷ����䶯���������ӻ������������,����Щ���Ӳ���C���ļ��ӡ�
�����鱨��Ҫ�о����˾�����ϰʲôս��,����TidyҪ��ʱ��Derek�㱨ĳһ�������Ĺ���Ӫ��һ���ж�����,����Derek��:��Tidy,���ϻ㱨��3��Ӫ�ص���10��Ӫ�ع��ж�����!��Tidy��Ҫ���Ͽ�ʼ������һ�ε����������㱨�����б�Ӫ�ص����������䶯����Derekÿ��ѯ�ʵĶζ���һ��������Tidy���ò�ÿ�ζ�һ��һ��Ӫ�ص�ȥ�����ܿ�;�ƣ�����ˣ�Derek��Tidy�ļ����ٶ�Խ��Խ����:"��������У������ô�����ҳ�������!��Tidy�룺�����Լ������㿴���������һ�����˵Ĺ���!�Һ޲����㳴��������!������֮�£�Tidyֻ�ô�绰������ר��Windbreaker���,Windbreaker˵���������У�����ƽʱ�����acm��Ϳ�����㷨�飬���ڳ�������˰�!��Tidy˵��"��֪���ˡ�����"��Windbreaker�Ѿ��ҵ��绰�ˡ�Tidy�ܿ��գ���ô������Ļ�����ģ������Ķ��ߣ�����д������������������𣿲��������ĳ���Ч�ʲ����ߵĻ���Tidy���ǻ��ܵ�Derek�������.

Input
��һ��һ������T����ʾ��T�����ݡ�
ÿ�����ݵ�һ��һ��������N��N<=50000��,��ʾ������N������Ӫ�أ���������N��������,��i��������ai�����i������Ӫ���￪ʼʱ��ai���ˣ�1<=ai<=50����
������ÿ����һ�����������4����ʽ��
(1) Add i j,i��jΪ������,��ʾ��i��Ӫ������j���ˣ�j������30��
(2)Sub i j ,i��jΪ������,��ʾ��i��Ӫ�ؼ���j���ˣ�j������30��;
(3)Query i j ,i��jΪ������,i<=j����ʾѯ�ʵ�i����j��Ӫ�ص�������;
(4)End ��ʾ����������������ÿ������������;
ÿ�����������40000������

Output
�Ե�i������,���������Case i:���ͻس�,
����ÿ��Queryѯ�ʣ����һ���������س�,��ʾѯ�ʵĶ��е�������,�����������int���ڡ�

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
��ά��
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
