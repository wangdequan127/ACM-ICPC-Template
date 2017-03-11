设m是正整数，a是整数，若a模m的阶等于φ(m)，则称a为模m的一个原根。
求原根目前的做法只能是从2开始枚举，然后暴力判断g^(P-1) = 1 (mod P)是否当且当指数为P-1的时候成立

快速求原根
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define LL long long

const int N = 1000010;

bool prime[N];
LL p[N];
LL pr[N];
LL k=0,c;

void isprime()
{
    LL i,j;
    memset(prime,true,sizeof(prime));
    for(i=2; i<N; i++)
    {
        if(prime[i])
        {
            p[k++]=i;
            for(j=i+i; j<N; j+=i)
            {
                prime[j]=false;
            }
        }
    }
}

void cal(LL n)
{
    LL t=n,i,a;
    c=0;
    for(i=0; p[i]*p[i]<=n; i++)
    {
        if(n%p[i]==0)
        {
            pr[c]=p[i];
            while(n%p[i]==0) n/=p[i];
            c++;
        }
    }
    if(n>1)
    {
        pr[c]=n;
        c++;
    }
}

LL quick_mod(LL a,LL b,LL m)
{
    LL ans=1;
    a%=m;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%m;
            b--;
        }
        b>>=1;
        a=a*a%m;
    }
    return ans;
}

int main()
{
    LL P,i,t,g,root;
    isprime();
    while(cin>>P)
    {
        cal(P-1);
        for(g=2; g<P; g++)
        {
            bool flag=true;
            for(i=0; i<c; i++)
            {
                t=(P-1)/pr[i];
                if(quick_mod(g,t,P)==1)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                root=g;
                cout<<root<<endl;
            }
        }
    }
    return 0;
}
http://blog.csdn.net/z690933166/article/details/11620267

设m是正整数，a是整数，若a模m的阶等于φ(m)，则称a为模m的一个原根。（其中φ(m)表示m的欧拉函数）
给出1个质数P，找出P最小的原根。
Input
输入1个质数P(3 <= P <= 10^9)
Output
输出P最小的原根。
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100000+10;
typedef long long LL;
bool prime[maxn];
int prim[maxn],k;
void make_prime()
{
    memset(prime,0,sizeof(prime));
    k=0;
    for(int i=2; i<maxn; i++)
        if(!prime[i])
        {
            prim[k++]=i;
            for(int j=0; j<k&&prim[j]<maxn/i; j++)
            {
                prime[i*prim[j]]=1;
                if(i%prim[j]==0) break;
            }
        }
}
int fac[50],num;
void divide(LL n)
{
    num=0;
    for(int i=0; prim[i]*prim[i]<=n; i++)
        if(n%prim[i]==0)
        {
            fac[num++]=prim[i];
            while(n%prim[i]==0) n/=prim[i];
        }
    if(n>1) fac[num++]=n;
}
LL pow_mod(LL a,LL b,LL mod)
{
    LL r=1;
    while(b)
    {
        if(b&1)
            r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}
int main()
{
    LL p;
    make_prime();
    while(cin>>p)
    {
        divide(p-1);
        for(int i=2; i<p; i++)
        {
            bool flag=true;
            for(int j=0; j<num; j++)
            {
                int x=(p-1)/fac[j];
                if(pow_mod(i,x,p)==1)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}


