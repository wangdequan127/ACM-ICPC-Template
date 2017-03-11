//快速幂
typedef long long mytype;
const long long mod = 1e9+7;
mytype quickpow(mytype a,mytype n)
{
    mytype res=1;
    while(n)
    {
        if(n&1)
            res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}


//快速幂加快速乘
typedef long long mytype;
const long long mod = 1e9+7;
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
mytype quickpow(mytype a,mytype n)
{
    mytype res=1;
    while(n)
    {
        if(n&1)
            res=quickmult(res,a);
        a=quickmult(a,a);
        n>>=1;
    }
    return res;
}



//快速乘
typedef long long mytype;
const long long mod = 1e9+7;
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

