#define len 500000
int next[len];
int s[len];
int sub[len];

void getnext(int sub[],int next[],int len2)
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<len2)
    {
        if (j==-1||sub[i]==sub[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}

int kmp(int s[],int sub[],int len1,int len2,int next[])
{
    int i,j;
    i=0;
    j=0;
    while(i<len1&&j<len2)
    {
        if(j==-1||s[i]==sub[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j>=len2)
    {
        return i-len2;
    }
    else
    {
        return -1;
    }
}

