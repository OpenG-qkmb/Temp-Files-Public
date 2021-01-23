#include <iostream>
#include <cstdio>
#include <cstring>
#define S 4
using namespace std;
typedef long long lld;
int n,m,x1,y1,x2,y2,ans(0);
bool mp[2048][2048];
const int dx[S]={0,1,0,-1},dy[S]={1,0,-1,0};
inline bool CheckDigit(char c)
{
	return ((c>='0')&&(c<='9'));
}
inline int getint()
{
	int x(0),f(1);
	char c(getchar());
	for(;(!CheckDigit(c));c=getchar())if(c=='-')f=-1;
	for(;CheckDigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
inline void putint(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)putint(x/10);
	putchar(x%10+'0');
	return;
}
void dfs(int x,int y)
{
	if((x>n)||(y>n)||(x<1)||(y<1)||(!mp[x][y]))
	{
		return;
	}
	mp[x][y]=false;
	for(register int i=0;i<S;++i)
	{
		int nx(x+dx[i]),ny(y+dy[i]);
		if((nx>n)||(ny>n)||(nx<1)||(ny<1)||(!mp[nx][ny]))
		{
			continue;
		}
		dfs(nx,ny);
	}
	return;
}
int main()/*OpenG-qkmb*/
{
	memset(mp,false,sizeof(mp));
	n=getint();
	m=getint();
	for(register int i=0;i<m;++i)
	{
		x1=getint();//   q
		y1=getint();//m  j
		x2=getint();//b, b!
		y2=getint();//   b
		for(register int j=x1;j<=x2;++j)
		{
			for(register int k=y1;k<=y2;++k)
			{
				mp[j][k]=true;
			}
		}
	}
	for(register int i=1;i<=n;++i)
	{
		for(register int j=1;j<=n;++j)
		{
			if(mp[i][j])
			{
				dfs(i,j);
				++ans;
			}
		}
	}
	putint(ans);
	putchar(10);
	return 0;
}//This TGT Kid can eat anyone's ****.
//我无语了。。。把ny=y+dy[i]打成ny=x+dy[i]，还没发现，也是服了。。。（样例都不能过）
