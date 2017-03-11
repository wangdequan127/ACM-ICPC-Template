http://blog.csdn.net/wust_zzwh/article/details/51966450

#include<vector>
#include<iostream>
#include<stdio.h>
#include<queue>
#include<cstring>
#include<cmath>
#include<map>
#include <string>
#include<algorithm>
#include<set>
#include<stack>
#define debug puts("xxxxxxx");
#define pi (acos(-1.0))
#define eps (1e-5)
#define inf 0x3f3f3f3f
#define mem(x) memset(x,0,sizeof(x))
typedef long long ll;
const int mx = 10000005;
const int mod = 1e9+7;
using namespace std;
int pri[mx],phi[mx],tot;
ll sum[mx];
bool vis[mx];
void init()
{
    int n=mx;
    tot=0;
    memset(vis,false,sizeof vis);
    phi[1]=1;
    for(int i=2; i<n; i++)
    {
        if(!vis[i])
        {
            pri[tot++]=i;
            phi[i]=i-1;
        }
        for(int j=0; j<tot && i*pri[j]<n; j++)
        {
            vis[i*pri[j]]=true;
            if(i%pri[j]==0)
            {
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            else phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
    }
    sum[0]=0;
    for(int i=1;i<mx;i++)
        sum[i]=(sum[i-1]+phi[i])%mod;
}
int rear;
int a[200];
void resolve(ll n)
{
    int i,j;
    rear=0;
    for(i=0;i<tot;i++)
    {
        if(!vis[n])
        {
            a[rear++]=n;
            break;
        }
        if(n%pri[i]==0)
        {
            a[rear++]=pri[i];
            n/=pri[i];
        }
    }
}
ll f(int pos,ll n,ll m)
{
//cout<<pos<<" "<<n<<' '<<m<<endl;
    if(n==1)
        return sum[m];
    if(m==0)return 0;
    if(m==1)
        return phi[n];
    ll p=a[pos];
    return ((p-1)*f(pos-1,n/p,m)+f(pos,n,m/p))%mod;
}
//ll f(int pos,ll n,ll m)
//{
//    ll M=mod;
//
//    //pos即每个素数，一次一个就行了
//    if(n==1) return sum[m];//n为1结果就是欧拉值的前缀和
//    if(m==0)return 0;
//    return ((a[pos]-1)*f(pos-1,n/a[pos],m)%M+f(pos,n,m/a[pos]))%M;
//}
typedef long long mytype;
mytype quickpow(mytype a,mytype n,mytype mmod)
{
    mytype res=1;
    while(n)
    {
        if(n&1)
            res=res*a%mmod;
        a=a*a%mmod;
        n>>=1;
    }
    if(res==0) res+=mmod;
    return res;
}

ll solve(ll k,ll q)
{
    if(q==1)
        return q;
    ll num=solve(k,phi[q]);
    return quickpow(k,num,q);
}
int main()
{
//    freopen("1006.in","r",stdin);
//    freopen("1006my.out","w",stdout);
    init();
    ll n,m,q;
    while(~scanf("%I64d%I64d%I64d",&n,&m,&q))
    {
        resolve(n);
        ll k=f(rear-1,n,m);
        ll ans=solve(k,q);
        printf("%I64d\n",ans%q);
    }

}

