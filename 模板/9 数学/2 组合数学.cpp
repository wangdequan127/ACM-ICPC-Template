二项式
const int CN=20;
long long c[CN][CN]= {};
void cinit()
{
    for(int i=0; i<CN; i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1; j<i; j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
}


//小的数据可以，大的数据不行，要用逆元处理除

ll cc(ll n,ll m)
{
    if(m>n)
        return 0;
    ll i,ans=1;
    for(i=m+1;i<=n;i++)
        ans=ans*i;
    for(i=2;i<=n-m;i++)
        ans=ans/i;
    return ans;
}

//处理大数据的

ll cc(ll n,ll m)
{
    if(m>n)
        return 0;
    ll a=1, b=1;
    if(m>n) return 0;
    while(m)
    {
        a=(a*n)%mod;
        b=(b*m)%mod;
        m--;
        n--;
    }
    return (ll)a*inv(b)%mod;
}

普通母函数
for(i=0; i<n; i++)
            {
                for(j=0; j<=m[i]; j++)
                    for(k=0; k+j*p[i]<=num; k++)
                        tmp[k+j*p[i]]+=ans[k];
                for(j=0; j<=num; j++)
                {
                    ans[j]=+tmp[j];
                    tmp[j]=0;
                    ans[j]%=10000;
                }
            }

指数型母函数
double tmp[mx*mx]= {0},ans[mx*mx]= {0},a[mx]= {0},arrange[mx*mx]= {1};
ll n,m,i,j,k,num=0;
    for(i=1; i<mx*mx; i++)
        arrange[i]=i*arrange[i-1];
    while(~scanf("%I64d%I64d",&n,&m))
    {
        memset(tmp,0,sizeof(tmp));
        memset(ans,0,sizeof(ans));
        memset(a,0,sizeof(a));
        for(i=0; i<n; i++)
            scanf("%lf",&a[i]);
        ans[0]=1;
        for(i=0; i<n; i++)
        {
            for(j=0; j<=a[i]; j++)
                for(k=0; k+j<=m; k++)
                    tmp[k+j]+=ans[k]/arrange[j];
            memcpy(ans,tmp,sizeof(ans));
            memset(tmp,0,sizeof(tmp));
        }
        printf("%.lf\n",ans[m]*arrange[m]);
    }
c(k, 1) + c(k, 3) + c(k, 5) +…… = 2^（k - 1)
c(k, 0) + c(k, 2) + c(k, 3) + c(k, 5) +…… = 2^（k - 1)
c(k, 0) + c(k, 1) + c(k, 2) +…… = 2^k
1*C(n,1)+2*C(n,2)+3*C(n,3)+…+n*C(n,n)=n*2^(n-1)
