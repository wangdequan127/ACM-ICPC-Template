long long mod=110119;
typedef long long mytype;
mytype quickmult(mytype a,mytype b)
{
    mytype res=0;
    while(b)
    {
        if(b&1)
        {
            res+=a;
            if(res>=mod)res-=mod;
        }
        a+=a;
        b>>=1LL;
        if(a>=mod)a-=mod;
    }
    return res;
}
long long PowMod(long long a,long long b)
{
    long long ret=1;
    while(b)
    {
        if(b&1)
            ret=quickmult(ret,a)%mod;
        a=quickmult(a,a)%mod;
        b>>=1;
    }
    return ret;
}
long long fac[1000005];
long long Get_Fact(long long p)
{
    fac[0]=1;
    for(int i=1; i<=p; i++)
        fac[i]=quickmult(fac[i-1],i)%p;
}
long long Lucas(long long n,long long m,long long p)
{
    long long ret=1;
    while(m)
    {
        long long a=n%mod,b=m%mod;
        if(a<b) return 0;
        ret=(ret*fac[a]*PowMod(fac[b]*fac[a-b]%p,p-2))%p;
        n/=p;
        m/=p;
    }
    return ret;
}

