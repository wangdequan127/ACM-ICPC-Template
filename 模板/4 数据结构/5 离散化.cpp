void discrete(int *aa,int nn)
{
    memcpy(cp,aa,sizeof(cp));
    sort(cp,cp+nn);
    int tot=unique(cp,cp+nn)-cp;
    for(int i=0;i<nn;i++)
        aa[i]=lower_bound(cp,cp+tot,aa[i])-cp+1;
}

