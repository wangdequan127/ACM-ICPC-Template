#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#define debug puts("----------")
//#define INF 0x3f3f3f3f
#define maxn 300005
using namespace std;

priority_queue<int> q;      //优先队列
vector<int> vec[maxn];
int b[maxn],num[maxn];
int m,n;

void init()
{
    memset(num,0,sizeof(num));
    for(int i = 1 ; i <= n ; i++)
        vec[i].clear();
}
int main()
{
    int t,x,y;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        int flag = 0;
        for(int i = 0 ; i < m ; i++)
        {
            scanf("%d%d",&x,&y);
            num[x]++;
            vec[y].push_back(x);
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if(num[i] == 0) q.push(i);
        }
        int temp  =  n;
        while(!q.empty())
        {
            temp--;
            int u = q.top();
            b[temp] = u;
            q.pop();
            for(int i = 0 ; i < vec[u].size() ; i++)
            {
                int v = vec[u][i];
                num[v]--;
                if(!num[v]) q.push(v);
            }
        }
        for(int i = 1 ; i <= n ; i++)
            if(num[i])
        {
            flag = 1;
            break;
        }
        if(flag) cout <<"NO"<<endl;
        else cout << "YES"<<endl;
    }
    return 0;
}
