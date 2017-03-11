const int MAXN=100005;
// �����㷨��������
struct point
{
    double x,y;
};
point p[MAXN];
int index[MAXN];  //����ɸѡ������������
int cmpx(const point &a,const point &b)
{
    return a.x<b.x;
}
int cmpy(int a,int b)  //�����õ����±�����
{
    return p[a].y<p[b].y;
}
inline double dis(point &a , point &b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}
inline double min(double a , double b)
{
    return a<b?a:b;
}
double closest(int low , int high)
{
    if(low+1==high)
        return dis(p[low],p[high]);
    if(low+2==high)
        return min( dis(p[low],p[high]) , min(dis(p[low],p[low+1]),dis(p[low+1],p[high])) );
    int mid = (low + high)>>1;//���е�
    double ans = min( closest(low,mid),closest(mid+1,high) );  //���η����еݹ����
    int cnt = 0;
    for(int i=low; i<=high; i++) //��x������p[mid].x-ans~p[mid].x+ans��Χ�ڵĵ�ȡ����
    {
        if(p[i].x >= p[mid].x - ans && p[i].x <= p[mid].x + ans)
            index[cnt++]=i;     //��������±�����
    }
    sort(index,index+cnt,cmpy);   //��y���������������
    for(int i=0; i<cnt; i++)
        for(int j=i+1; j<cnt; j++)
        {
            if(p[index[j]].y - p[index[i]].y >= ans)   //ע���±�����
                break;
            ans = min( ans,dis(p[index[i]],p[index[j]]) );
        }
    return ans;
}
void init(int n)
{
    for (int i=0; i<n; i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    sort(p,p+n,cmpx);
    return;
}
int main()
{
    int n;
    while(cin>>n,n!=0)
    {
        init(n);
        printf("%.2lf\n",closest(0,n-1)/2);
    }
    return 0;
}

