
//≤ªª•÷ 
void crt()
{
    int t;
    while(cin>>t)
    {
        int flag=1;
        long long n1,a1;
        if (t) scanf("%lld%lld",&n1,&a1),t--;
        while(t--)
        {
            long long n2,a2,k1,k2;
            scanf("%lld%lld",&n2,&a2);
            if (flag==0)
                continue;
            long long d=exgcd(n1,n2,k1,k2);
            if ((a2-a1)%d!=0)
                flag=0;
            if (flag)
            {
                k1=(k1*(a2-a1)/d%(n2/d)+n2/d)%(n2/d);
                long long a=n1*k1+a1;
                long long n=n1/d*n2;
                n1=n;
                a1=a;
            }
        }
        if (flag) return a1;
        else return -1;
    }
}

//ª•÷ 
ll China(ll r) {
    ll M = 1, ans = 0;
    for (ll i = 0; i < r; ++i)
        M *= m[i];
    for(ll i = 0;i < r;i++) {
        ll N = M/m[i];
        ll x, y;
        extend_gcd(N, m[i], x, y);
        x = (x%m[i]+m[i])%m[i];
        ans = ((ans+a[i]*N%M*x%M)%M + M)%M;
    }
    return ans;
}

int China(int r) {
    int M = 1, ans = 0;
    for (int i = 0; i < r; ++i)
        M *= m[i];
    for(int i = 0;i < r;i++) {
        int N = M/m[i];
        int x, y;
        extend_gcd(N, m[i], x, y);
        x = (x%m[i]+m[i])%m[i];
        ans = ((ans+a[i]*N%M*x%M)%M + M)%M;
    }
    return ans;
}
