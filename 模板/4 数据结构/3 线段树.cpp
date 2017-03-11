#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int NV = 100005;
#define INF 0x3f3f3f3f
int n,m;


struct node
{
    long long oo,oj,jo,jj;
    node():oo(-INF),oj(-INF),jj(-INF),jo(-INF) {}
}sum[NV<<2];

long long max(long long a,long long b)
{
    if(a > b) return a;
    else return b;
}

void PushUp(int rt)
{
    sum[rt].jj = max(max(sum[rt<<1].jj,sum[rt<<1|1].jj),max(sum[rt<<1].jj+sum[rt<<1|1].oj,sum[rt<<1].jo+sum[rt<<1|1].jj));

    sum[rt].oo = max(max(sum[rt<<1].oo,sum[rt<<1|1].oo),max(sum[rt<<1].oo+sum[rt<<1|1].jo,sum[rt<<1].oj+sum[rt<<1|1].oo));

    sum[rt].jo = max(max(sum[rt<<1].jo,sum[rt<<1|1].jo),max(sum[rt<<1].jj+sum[rt<<1|1].oo,sum[rt<<1].jo+sum[rt<<1|1].jo));

    sum[rt].oj = max(max(sum[rt<<1].oj,sum[rt<<1|1].oj),max(sum[rt<<1].oo+sum[rt<<1|1].jj,sum[rt<<1].oj+sum[rt<<1|1].oj));


}
void build(int l,int r,int rt=1)
{
    if (l == r)
    {
        if(l % 2 == 1)
        {
        scanf("%I64d",&sum[rt].jj);
        sum[rt].oo = sum[rt].jo = sum[rt].oj = -INF;

        }
        else
        {
            scanf("%I64d",&sum[rt].oo);
            sum[rt].jj = sum[rt].oj = sum[rt].jo = -INF;

        }
            //此处为sum[rt]赋值，即为scanf("%d",&sum[rt]);
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(long long L,long long c,int l,int r,int rt=1)  //L为插入位置，c为增加的值
{
    if (L == l && l == r)
    {

        if(l % 2 == 1)
        {
            sum[rt].jj = c;
            sum[rt].oj = sum[rt].oo = sum[rt].jo = -INF;
        }
        else
        {
            sum[rt].oo = c;
            sum[rt].jj = sum[rt].oj = sum[rt].jo = -INF;
        }
        return ;
    }
    int m = (l + r) >> 1;
    if (L <= m) update(L , c , lson);
    else update(L , c , rson);
    PushUp(rt);
}



node query(long long  L,long long R,int l,int r,int rt=1)//(L,R)为要查询的区间
{
    node temp,ltemp,rtemp;
    if (L <= l && r <= R)
        {
            temp.jj = sum[rt].jj;
            temp.oo = sum[rt].oo;
            temp.oj = sum[rt].oj;
            temp.jo = sum[rt].jo;
            return temp;
        }
    int m = (l + r) >> 1;
    if (L <= m) ltemp = query(L , R , lson);
    if (m < R) rtemp = query(L , R , rson);      //注：两个判断都为if

     temp.jj=max(max(max(ltemp.jj+rtemp.oj,ltemp.jo+rtemp.jj),ltemp.jj),rtemp.jj);
     temp.oo=max(max(max(ltemp.oo+rtemp.jo,ltemp.oj+rtemp.oo),ltemp.oo),rtemp.oo);
     temp.jo=max(max(max(ltemp.jo+rtemp.jo,ltemp.jj+rtemp.oo),ltemp.jo),rtemp.jo);
     temp.oj=max(max(max(ltemp.oj+rtemp.oj,ltemp.oo+rtemp.jj),ltemp.oj),rtemp.oj);
      return temp;
}

int main()
{
    int t;
    long long b,c;
    int a;
    scanf("%d",&t);
    while(t--){
     scanf("%d%d",&n,&m);
     build(1,n,1);
     for(int i = 0 ; i < m ; i++)
     {
         scanf("%d%I64d%I64d",&a,&b,&c);
         if(a == 1)
         {
             update(b,c,1,n);
         }
         else
         {
             node tempc = query(b,c,1,n);
             long long ans = max(max(max(tempc.oo,tempc.jj),tempc.jo),tempc.oj);
             printf("%I64d\n",ans);
         }
     }

    }
    return  0;

}

