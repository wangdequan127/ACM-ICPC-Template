long long quickpow(long long a, long long b) {
    if (b < 0) return 0;
    long long ret = 1;
    a %= mod;
    while(b) {
        if (b & 1) ret = (ret * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ret;
}
//费马小定理求逆元（M必须是质数）
long long inv(long long a) {
    return quickpow(a, mod - 2);
}

/*
a/b)%Mod=c;    (b*p)%Mod=1;    ==》   (a/b)*(b*p) %Mod=c;    ==》    (a*p)%Mod=c;  其中p是逆元
const int mod = 1000000009;


新学的一个求逆元的方法：
inv[i] = ( MOD - MOD / i ) * inv[MOD%i] % MOD
证明：
设t = MOD / i , k = MOD % i
则有 t * i + k == 0 % MOD
有 -t * i == k % MOD
两边同时除以ik得到
-t * inv[k] == inv[i] % MOD
即
inv[i] == -MOD / i * inv[MOD%i]
即
inv[i] == ( MOD - MOD / i) * inv[MOD%i]
证毕
适用于MOD是质数的情况，能够O(n)时间求出1~n对模MOD的逆

*/
