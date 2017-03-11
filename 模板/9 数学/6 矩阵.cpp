typedef long long mytype;
const int SZ=105;
const long long M=1000000007;
long long quickpow(long long a, long long b)
{
    if(b < 0) return 0;
    long long ret = 1;
    a %= M;
    for (; b; b >>= 1, a = (a * a) % M)
        if (b & 1)
            ret = (ret * a) % M;
    return ret;
}
long long inv(long long a)
{
    return quickpow(a,M-2);
}
struct mat
{
    int n,m;
    mytype a[SZ][SZ];
    void init()
    {
        memset(a,0,sizeof(a));
    }
    mat(int n=SZ,int m=SZ):n(n),m(m) {}
    mat unit()
    {
        mat t(n,n);
        t.init();
        for (int i=0; i<n; i++)
            t.a[i][i]=1;
        return t;
    }
    mytype *operator [](int n)
    {
        return *(a+n);
    }
    mat operator +(const mat &b)
    {
        mat t(n,m);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                t.a[i][j]=(a[i][j]+b.a[i][j]+M)%M;
        return t;
    }
    mat operator -(const mat &b)
    {
        mat t(n,m);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                t.a[i][j]=(a[i][j]-b.a[i][j]+M)%M;
        return t;
    }
    mat operator *(const mat &b)
    {
        mat t(n,m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                t.a[i][j]=0;
                for(int k=0; k<m; k++)
                    t.a[i][j]=(t.a[i][j]+(a[i][k]*b.a[k][j])%M)%M;
            }
        return t;
    }
    mat operator *(const mytype &b)
    {
        mat t(n,m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                t.a[i][j]=a[i][j]*b%M;
        return t;
    }
    mat operator /(const mytype &b)
    {
        mat t(n,m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                t.a[i][j]=a[i][j]*inv(b)%M;
        return t;
    }
    mat operator !()
    {
        mat t(n,m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                t.a[i][j]=a[j][i];
        return t;
    }
    mytype det()
    {
    }
    mat invm(mat &a)
    {
    }
    friend mat quickpow(mat a, mytype b)
    {
        if(b<0) return a.unit();
        mat ret=a.unit();
        for (; b; b>>=1,a=a*a)
            if (b&1)
                ret=ret*a;
        return ret;
    }
    void in()
    {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                scanf("%lld",&a[i][j]);
    }
    void out()
    {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                printf("%lld%c",a[i][j]," \n"[j==m-1]);
    }
};


矩阵快速幂
#define mod 10000007
const int maxn = 10;
const int maxm = 10;
ll k;
int n;
int num[100005];
struct Matrix {
    int n, m;
    long long a[maxn][maxm];
    void clear() {
        n = m = 0;
        memset(a, 0, sizeof(a));
    }
    Matrix operator * (const Matrix &b) const { //实现矩阵乘法
        Matrix tmp;
        tmp.n = n;
        tmp.m = b.m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < b.m; j++) tmp.a[i][j] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (!a[i][j]) continue;
                for (int k = 0; k < b.m; k++)
                    tmp.a[i][k] += a[i][j] * b.a[j][k]%mod , tmp.a[i][k] %= mod;
            }

        return tmp;
    }
    void Copy(const Matrix &b) {
        n = b.n, m = b.m;
        for (int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) a[i][j] = b.a[i][j];
    }
    void unit(int sz) {
        n = m = sz;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) a[i][j] = 0;
            a[i][i] = 1;
        }
    }
};
Matrix A, B;
void init() {
    A.clear(); //矩阵A是构造的矩阵
    A.n = A.m = 3;
    A.a[0][0] = 1;
    A.a[0][1] = 1;
    A.a[1][0] = 1;
    A.a[2][0] = 1;
    A.a[2][1] = 1;
    A.a[2][2] = 1;
    B.clear();
    B.n = 3;
    B.m = 1;
}
//Matrix Matrix_pow(Matrix A,ll k, ll mod) {
Matrix Matrix_pow(Matrix A,ll k)
{
    Matrix res;
    res.clear();
    res.n = res.m = 3;
    for (int i = 0; i < 10; i++) res.a[i][i] = 1;
    while(k) {
        if (k & 1) res.Copy(A * res);
        k >>= 1;
        A.Copy(A * A);
    }
    return res;
}


