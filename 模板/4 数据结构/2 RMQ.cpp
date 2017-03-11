/*
下标从1开始
*/
const int NV = 255;
const int NVB = 20;
int mx[NV][NVB],mn[NV][NVB],a[NV];
void init(int data[],int n)
{
    int k = log2(n);
    for(int i=1; i<=n; i++)
        mx[i][0] = mn[i][0] = data[i];
    for(int j=1; j<=k; j++)
    {
        for(int i=1; i+(1<<j)-1<=n; i++)
        {
            mx[i][j] = max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
            mn[i][j] = min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r,int flag)
{
    int k = log2(r-l+1);
    if(flag)
        return max(mx[l][k],mx[r-(1<<k)+1][k]);
    else
        return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
二维
int val[255][255];
int mm[255];
int dpmin[255][255][8][8];//最小值
int dpmax[255][255][8][8];//最大值

void initRMQ(int n,int m)
{
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            dpmin[i][j][0][0] = dpmax[i][j][0][0] = val[i][j];
    for(int ii = 0; ii <= mm[n]; ii++)
        for(int jj = 0; jj <= mm[m]; jj++)
            if(ii+jj)
                for(int i = 1; i + (1<<ii) - 1 <= n; i++)
                    for(int j = 1; j + (1<<jj) - 1 <= m; j++)
                    {
                        if(ii)
                        {
                            dpmin[i][j][ii][jj] = min(dpmin[i][j][ii-1][jj],dpmin[i+(1<<(ii-1))][j][ii-1][jj]);
                            dpmax[i][j][ii][jj] = max(dpmax[i][j][ii-1][jj],dpmax[i+(1<<(ii-1))][j][ii-1][jj]);
                        }
                        else
                        {
                            dpmin[i][j][ii][jj] = min(dpmin[i][j][ii][jj-1],dpmin[i][j+(1<<(jj-1))][ii][jj-1]);
                            dpmax[i][j][ii][jj] = max(dpmax[i][j][ii][jj-1],dpmax[i][j+(1<<(jj-1))][ii][jj-1]);
                        }
                    }
}
//查询矩形的最大值
int rmq1(int x1,int y1,int x2,int y2)
{
    int k1 = mm[x2-x1+1];
    int k2 = mm[y2-y1+1];
    x2 = x2 - (1<<k1) + 1;
    y2 = y2 - (1<<k2) + 1;
    return max(max(dpmax[x1][y1][k1][k2],dpmax[x1][y2][k1][k2]),max(dpmax[x2][y1][k1][k2],dpmax[x2][y2][k1][k2]));
}
//查询矩形的最小值
int rmq2(int x1,int y1,int x2,int y2)
{
    int k1 = mm[x2-x1+1];
    int k2 = mm[y2-y1+1];
    x2 = x2 - (1<<k1) + 1;
    y2 = y2 - (1<<k2) + 1;
    return min(min(dpmin[x1][y1][k1][k2],dpmin[x1][y2][k1][k2]),min(dpmin[x2][y1][k1][k2],dpmin[x2][y2][k1][k2]));
}

