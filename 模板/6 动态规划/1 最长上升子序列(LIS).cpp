//导弹拦截代码
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i,k=1,j,a[30]={0},b[30]={0};
    for(i=1;i<=n;i++)
        cin>>a[i];
    b[1]=a[1];
    for(i=2;i<=n;i++)
        if(a[i]<=b[k])
        {
            b[k+1]=a[i];
            k++;
        }
        else
        {
            int p[k];
            for(j=0;j<k;j++)
                p[j]=b[k-j];
            int m=lower_bound(p,p+k,a[i])-p;
            b[k-m+1]=a[i];
        }
        cout<<k;
}

//求最长上升子序列
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i,k=0,a[n],b[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    b[0]=a[0];
    for(i=1;i<n;i++)
         if(a[i]>b[k])
            b[++k]=a[i];
        else
        {
            int m=lower_bound(b,b+k+1,a[i])-b;
            if(b[m]!=a[i])
            b[m]=a[i];
        }
        for(i=0;i<k+1;i++)
            cout<<b[i]<<endl;
        cout<<k+1;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],l[n],i,j;
    for(i=0; i<n; i++)
        cin>>a[i];
    for(i=0; i<n; i++)
    {
        l[i]=1;
        for(j=0; j<i; j++)
            if(a[i]>a[j])
        l[i]=max(l[j]+1,l[i]);
    }
    int m=0;
    for(i=0; i<n; i++)
        if(l[i]>m)
            m=l[i];
    cout<<m;
    return 0;
}

