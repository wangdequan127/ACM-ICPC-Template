void rader(complex *F,int len)
{
    int j=len/2;///ģ������Ʒ�ת��λ�ĵ�λ��
    for(int i=1; i<len-1; i++)
    {
        if(i<j)swap(F[i],F[j]);///�ó���ʱ�ͳ���
        int k=len/2;
        while(j>=k)
        {
            j-=k;
            k>>=1;
        }
        if(j<k)j+=k;
    }


