#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long lld;
const lld S(1<<8),dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
lld n,a[S][S],len[S],ans(0);
char st[S+300];
struct tgt
{
	lld x,y;
};
queue<tgt>q;
inline bool CheckDigit(char c)
{
	return ((c>='0')&&(c<='9'));
}
inline bool eng(char c)
{
	return ((c>='a')&&(c<='z'));
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
inline tgt cbs(lld x,lld y)
{
	return (tgt){x,y};
}
inline void bfs(lld x,lld y)
{
	q.push(cbs(x,y));
	while(!q.empty())
	{
		tgt tmp(q.front());
		q.pop();
		for(register lld i(0);i<4;++i)
		{
			lld nx(tmp.x+dx[i]),ny(tmp.y+dy[i]);
			if((nx<1)||(ny<1)||(nx>n)||(ny>len[nx])||(!a[nx][ny]))
				continue;
			a[nx][ny]=0,q.push(cbs(nx,ny));
		}
	}
	return;
}
int main()/*OpenG-qkmb*/
{
	cin.getline(st,S);
	sscanf(st,"%d",&n);
	for(register lld i(1);i<=n;++i)
	{
		cin.getline(st,S);
		len[i]=strlen(st);
		for(register lld j(1);j<=len[i];++j)
		{
			a[i][j]=eng(st[j-1]);
		}
	}
//	for(register lld i(1);i<=n;++i)
//	{
//		for(register lld j(1);j<=len[i];++j)
//		{
//			putint(a[i][j]),putchar(32);
//		}
//		putchar(10);
//	}
	for(register lld i(1);i<=n;++i)
	{
		for(register lld j(1);j<=len[i];++j)
		{
			if(a[i][j])
			{
				a[i][j]=0,++ans,bfs(i,j);
			}
		}
	}
	return putint(ans),putchar(10),0;
}