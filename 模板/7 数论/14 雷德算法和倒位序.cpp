void rader(complex *F,int len)
{
    int j=len/2;///模拟二进制反转进位的的位置
    for(int i=1; i<len-1; i++)
    {
        if(i<j)swap(F[i],F[j]);///该出手时就出手
        int k=len/2;
        while(j>=k)
        {
            j-=k;
            k>>=1;
        }
        if(j<k)j+=k;
    }


