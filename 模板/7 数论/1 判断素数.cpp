int isprime(int n)
{
    if (n==1)
        return 0;
    int x=sqrt(n*1.0);
    for (int i=2; i<=x; i++)
        if (n%i==0)
            return 0;
    return 1;
}

