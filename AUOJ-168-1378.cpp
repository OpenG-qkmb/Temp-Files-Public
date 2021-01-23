#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long lld;
const lld S(1<<7),dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
lld n,m,a[S][S],lima[S],v,cnt(0),cnt2(0);
bool visit[S][S],gt[S];
inline bool CheckDigit(char c)
{
	return ((c>='0')&&(c<='9'));
}
inline lld getint()
{
	lld x(0),f(1);
	char c(getchar());
	for(;(!CheckDigit(c));c=getchar())if(c=='-')f=-1;
	for(;CheckDigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
inline void putint(lld x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)putint(x/10);
	putchar(x%10+'0');
	return;
}
inline void dfs(lld x,lld y)
{
	for(register lld i(0);i<4;++i)
	{
		lld nx(x+dx[i]),ny(y+dy[i]);
		if((nx<1)||(ny<1)||(nx>n)||(ny>n)||(visit[nx][ny])||(a[nx][ny]!=v))
			continue;
		visit[nx][ny]=true;
		dfs(nx,ny);
	}
	return;
}
int main()/*OpenG-qkmb*/
{
	n=getint(),m=getint();
	if(m>n)return puts("FXXK!!!"),0;
	for(register lld i(1);i<=n;++i)
	{
		for(register lld j(1);j<=n;++j)
		{
			a[i][j]=getint();
		}
	}
	v=a[n][m],visit[n][m]=true;
	dfs(n,m);
	for(register lld i(1);i<=n;++i)
	{
		for(register lld j(1);j<=n;++j)
		{
			if(visit[i][j])a[i][j]=0,gt[j]=true;
		}
	}
//	for(register lld i(1);i<=n;++i)
//	{
//		for(register lld j(1);j<=n;++j)
//		{
//			putint(a[i][j]),putchar(32);
//		}
//		putchar(10);
//	}
//	getchar();
	for(register lld j(1);j<=n;++j)
	{
		if(gt[j])
		{
			memset(lima,cnt2=cnt=0,sizeof(lima));
			for(register lld i(n);i>0;--i)
			{
				if(a[i][j])
					lima[++cnt]=a[i][j],
					a[i][j]=0;
			}
			for(register lld i(n);i>0,cnt2<=cnt;--i)
			{
				a[i][j]=lima[++cnt2];
			}
		}
	}
	for(register lld i(1);i<=n;++i)
	{
		for(register lld j(1);j<=n;++j)
		{
			putint(a[i][j]),putchar(32);
		}
		putchar(10);
	}
	return 0;
}