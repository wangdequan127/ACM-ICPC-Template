#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<map>
#include <string>
#include<algorithm>
#include<set>
#include<stack>
#define debug puts("xxxxxxx");
#define pi (acos(-1.0))
#define eps (1e-5)
#define inf 0x3f3f3f3f
#define mem(x) memset(x,0,sizeof(x))
#define sfl(x) scanf("%I64d",&x)
#define sfl2(x,y) scanf("%I64d%I64d",&x,&y)
#define sfl3(x,y,z) scanf("%I64d%I64d%I64d",&x,&y,&z)
#define sf(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
typedef long long ll;
const int mx = 1005;
void fre()
{
    freopen("1003.in","r", stdin);
    freopen("1003my.out","w", stdout);
}
const long long mod = 1e9+7;
using namespace std;


#include <bits/stdc++.h>
#define debug puts("xxxxxxx");
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf 0x3f3f3f3f
#define mx 200005
#define mem(x) memset(x,0,sizeof(x))
typedef long long ll;
using namespace std;
freopen("input.txt","r", stdin);freopen("output.txt","w", stdout);
void fre()
{
    freopen("a.in","r", stdin);
    freopen("a.out","w", stdout);
}
#pragma comment(linker, "/STACK:102400000,102400000")


template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) pt(x / 10);
    putchar(x % 10 + '0');
}

