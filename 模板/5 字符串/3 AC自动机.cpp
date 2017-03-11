#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<set>
#include<stack>
#include<vector>
#include<map>
#define pi acos(-1.0)
#define inf 1<<29
#define debug puts("**********");
#define mem(x) memset(x,0,sizeof(x))
const int mx = 20010;
typedef long long ll;
using namespace std;
int tot=0;
char aim[100010][10010];
int num[100010];
int n,m;
 struct trie
{
    int next[500010][26],fail[500010],ed[500010];
    int root,L;
    int newnode()
    {
        for(int i = 0; i < 26; i++)
            next[L][i] = -1;
        ed[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0; i < len; i++)
        {
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
                now = next[now][buf[i]-'a'];
        }
        if(ed[now]==-1)
        {
            ed[now]=1;
        }
        else
        ed[now]++;
    }
    void build()
    {
        queue<int> q;
        fail[root] = root;
        for(int i = 0; i < 26; i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            for(int i = 0; i < 26; i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    q.push(next[now][i]);
                }
        }
    }
    int query(char buf[])
    {
        memset(num,0,sizeof(num));
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i = 0; i < len; i++)
        {
            now = next[now][buf[i]-'a'];
            int temp = now;
            while(temp != root)
            {
                if(ed[temp]!=-1)
                {
                    num[ed[temp]]+=ed[temp];
                    //res += ed[temp];
                }
                //tot++;
                //printf("%d====",res);
                //ed[temp] = 0;
                temp = fail[temp];
            }
        }
    return res;
    }
    void Debug()
    {
        for(int i = 0; i < L; i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],ed[i]);
            for(int j = 0; j < 26; j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
};
char buf[1000010];
trie ac;
int main()
{
    int t;
    //int n;
    scanf("%d",&t);
    while(t--)
    {
        //int n,m;
        scanf("%d%d",&n,&m);
        ac.init();
        for(int i = 0; i < n; i++)
        {
            scanf("%s",aim[i]);
            //ac.insert(aim[i]);
        }
        for(int i=0;i<m;i++)
        {
        scanf("%s",buf);
        ac.insert(buf);
        //printf("%d\n",ac.query(buf,dex));
        //printf("%d\n",tot);
        }
        ac.build();
        for(int i=0;i<n;i++)
        {
            ac.query(aim[i]);
            int ans=0;
            for(int i=0;i<m;i++)
            {
                ans+=num[i];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

