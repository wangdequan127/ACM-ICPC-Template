int dfs(int pos, int s, bool e) //e==1��ʾ���ˣ���ǰpos֮ǰ����λ����ͬ��
{
    if (pos==-1) return s==target_s; //���� ��ǰ״̬==Ŀ��״̬
    if (~f[pos][s] && !e ) return f[pos][s]; //���ֵ�Ѿ��������û���򷵻ؼ�¼��ֵ
    int ans = 0;
    int u = e ? bit[pos] : 9; //9������Ӧ�ĳɽ���
    for (int i = 0; i <= u; ++i)
        ans += dfs(pos-1, new_s(s, i), e&&i==u); //new_s��ʾ�µ�״̬�����⣬���϶�������Ŀ��״̬����״̬����ֱ��continue��
    return e ? ans : f[pos][s]=ans; //������˾�ֱ�ӷ��أ������¼�ٷ���
}
int solve(int n)
{
    memset(f,-1,sizeof(f));
    int pos=-1;
    while(n)
    {
        bit[++pos]=n%10; //10Ϊ����
        n/=10;
    }
    return dfs(pos,0,1); //��ʼ״̬
}

int f[20][5];
int bit[20];
int dfs(int pos, int s, bool e)
{
    if (pos==-1) return s==0||s==1;
    if (~f[pos][s]&&!e) return f[pos][s];
    int ans=0;
    int u=e?bit[pos]:9;
    for (int i=0; i<=u; ++i)
    {
        if(i==4||s==1&&i==2)
            continue;
        ans+=dfs(pos-1,i==6,e&&i==u);
    }
    return e?ans:f[pos][s]=ans;
}
int solve(int n)
{
    memset(f,-1,sizeof(f));
    int pos=-1;
    while(n)
    {
        bit[++pos]=n%10;
        n/=10;
    }
    return dfs(pos,0,1);
}

