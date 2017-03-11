归并排序求逆序数

题目网址
http://poj.org/problem?id=1804
详解博客
http://blog.csdn.net/acdreamers/article/details/16849761
实际上归并排序的交换次数就是这个数组的逆序对个数，为什么呢？


我们可以这样考虑：


归并排序是将数列a[l,h]分成两半a[l,mid]和a[mid+1,h]分别进行归并排序，然后再将这两半合并起来。
在合并的过程中（设l<=i<=mid，mid+1<=j<=h），当a[i]<=a[j]时，并不产生逆序数；当a[i]>a[j]时，在
前半部分中比a[i]大的数都比a[j]大，将a[j]放在a[i]前面的话，逆序数要加上mid+1-i。因此，可以在归并
排序中的合并过程中计算逆序数.
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
const int N = 1005;

int a[N],tmp[N];
int ans;

void Merge(int l,int m,int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    while(i <= m && j <= r)
    {
        if(a[i] > a[j])
        {
            tmp[k++] = a[j++];
            ans += m - i + 1;
        }
        else
        {
            tmp[k++] = a[i++];
        }
    }
    while(i <= m) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int i=l;i<=r;i++)
        a[i] = tmp[i];
}

void Merge_sort(int l,int r)
{
    if(l < r)
    {
        int m = (l + r) >> 1;
        Merge_sort(l,m);
        Merge_sort(m+1,r);
        Merge(l,m,r);
    }
}

int main()
{
    int n,T,tt=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        ans = 0;
        Merge_sort(0,n-1);
        printf("Scenario #%d:\n%d\n\n",tt++,ans);
    }
    return 0;
}


