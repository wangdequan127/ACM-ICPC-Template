//������������λ��

#include<stdio.h>
#include<string.h>
struct node {
    int l,r,val;
}tree[100005];
int tot=1;
void init(int tot)
{
    tree[tot].l=tree[tot].r=0;
}
void insert(int x,int val)
{
   if(tree[x].l&&val<tree[x].val)insert(tree[x].l,val);
   else if(tree[x].r&&val>tree[x].val)insert(tree[x].r,val);
   else {
       init(tot);
       tree[tot].val=val;
       if(tree[x].val>val)tree[x].l=tot;
       else tree[x].r=tot;
       tot++;
   }
}
void query(int x,int val)
{
    if(val==tree[x].val){printf("\n");return;}
    if(tree[x].val>val){
        printf("E");
        query(tree[x].l,val);
    }
    else {
        printf("W");
        query(tree[x].r,val);
    }
}
int main()
{
    int T,i,j,k,n,a[1005],b[1005],q,x;
    scanf("%d",&T);
    while(T--)
    {
         tot=1;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(i==1){
                init(tot);
                tree[tot].val=a[i];
                tot++;
            }
            else insert(1,a[i]);
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&x);
            query(1,x);
        }
    }
    return 0;
}

