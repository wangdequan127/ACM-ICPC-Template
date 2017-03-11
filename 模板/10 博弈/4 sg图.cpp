int sg[mx];
    int v[mx];
    int i,j;
    for(i=1; i<mx; i++)
    {
        int x=i;
        mem(v);
        for(j=1; j<=x; j*=2)
            v[sg[x-j]]++;
        for(j=0; j<mx; j++)
            if(v[j]==0)
                break;
        sg[i]=j;
    }


