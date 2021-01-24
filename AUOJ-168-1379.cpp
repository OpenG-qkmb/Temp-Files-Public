#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long lld;
const lld S(1<<6),dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
lld n,m,a[S][S],ans(0);
bool visit[S][S];
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
inline void ck()
{
	return void(puts("Fxxk!"));
}
inline void dfs(lld x,lld y,lld v)
{
	lld mx(1),mxv(-1);
	bool gtgt(false);
	ans=((v+a[x][y])>ans)?(v+a[x][y]):ans;
	if((x==n)&&(y==m))
	{
		return;
	}
	for(register lld i(0);i<4;++i)
	{
		lld nx(x+dx[i]),ny(y+dy[i]);
		if((nx<1)||(ny<1)||(nx>n)||(ny>m)||(visit[nx][ny]))
			continue;
		if(a[nx][ny]>mxv)
		{
			mxv=a[nx][ny],mx=i,gtgt=true;
		}
	}
	if(!gtgt)return;
	lld xx(x+dx[mx]),xy(y+dy[mx]);
	visit[xx][xy]=true;
	dfs(xx,xy,v+a[x][y]);//ck();
	return;
}
int main()/*OpenG-qkmb*/
{
	visit[1][1]=true,n=getint(),m=getint();
	for(register lld i(1);i<=n;++i)
	{
		for(register lld j(1);j<=m;++j)
		{
			a[i][j]=getint();
		}
	}
	dfs(1,1,0);
	return putint(ans),putchar(10),0;
}