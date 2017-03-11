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
//����С��������Ԫ��M������������
long long inv(long long a) {
    return quickpow(a, mod - 2);
}

/*
a/b)%Mod=c;    (b*p)%Mod=1;    ==��   (a/b)*(b*p) %Mod=c;    ==��    (a*p)%Mod=c;  ����p����Ԫ
const int mod = 1000000009;


��ѧ��һ������Ԫ�ķ�����
inv[i] = ( MOD - MOD / i ) * inv[MOD%i] % MOD
֤����
��t = MOD / i , k = MOD % i
���� t * i + k == 0 % MOD
�� -t * i == k % MOD
����ͬʱ����ik�õ�
-t * inv[k] == inv[i] % MOD
��
inv[i] == -MOD / i * inv[MOD%i]
��
inv[i] == ( MOD - MOD / i) * inv[MOD%i]
֤��
������MOD��������������ܹ�O(n)ʱ�����1~n��ģMOD����

*/
