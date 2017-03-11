/*
欧拉函数是指：对于一个正整数n，小于n且和n互质的正整数（包括1）的个数，记作φ(n) 。
通式：φ(x)=x*(1-1/p1)*(1-1/p2)*(1-1/p3)*(1-1/p4)…..(1-1/pn),其中p1, p2……pn为x的所有质因数，x是不为0的整数。φ(1)=1（唯一和1互质的数就是1本身）。
对于质数p，φ(p) = p - 1。注意φ(1)=1.
欧拉定理：对于互质的正整数a和n，有aφ(n) ≡ 1 mod n。
欧拉函数是积性函数——若m,n互质，φ(mn)=φ(m)φ(n)。
                                 若n是质数p的k次幂，φ(n)=p^k-p^(k-1)=(p-1)p^(k-1)，因为除了p的倍数外，其他数都跟n互质。
特殊性质：当n为奇数时，φ(2n)=φ(n)
欧拉函数还有这样的性质：
设a为N的质因数，若(N % a == 0 && (N / a) % a == 0) 则有E(N)=E(N / a) * a；若(N % a == 0 && (N / a) % a != 0) 则有：E(N) = E(N / a) * (a - 1)。
通式：

,其中p1, p2……pn为x的所有质因数，x是不为0的整数。φ(1)=1（唯一和1互质的数(小于等于1)就是1本身）。 (注意：每种质因数只一个。比如12=2*2*3那么φ（12）=12*（1-1/2）*(1-1/3)=4
若n是质数p的k次幂，

，因为除了p的倍数外，其他数都跟n互质。
设n为正整数，以 φ(n)表示不超过n且与n互
素的正整数的个数，称为n的欧拉函数值，这里函数
φ：N→N，n→φ(n)称为欧拉函数。
欧拉函数是积性函数——若m,n互质，

特殊性质：当n为奇数时，

, 证明与上述类似。
若n为质数则



∑d|nφ(d)=n


*/


//欧拉函数
long long phi(long long n)
{
    long long ans=n;
    long long x=sqrt(n);
    for (long long i=2; i<=x; i++)
    {
        if (n%i==0)
        {
            while(n%i==0)
                n/=i;
            ans=ans/i*(i-1);
        }
    }
    if (n>1)
        ans=ans/n*(n-1);
    return ans;
}

//欧拉函数打表
const int MAXN=10005;
long long phi[MAXN];
void getphi()
{
    for (int i=1; i<MAXN; i++)
        phi[i]=i;
    for (int i=2; i<MAXN; i++)
        if (phi[i]==i)
            for (int j=i; j<MAXN; j+=i)
                phi[j]=phi[j]/i*(i-1);
}

//筛选素数的过程中求出欧拉函数：
int pri[mx],phi[mx],tot;
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
}
