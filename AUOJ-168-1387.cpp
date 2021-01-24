#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long lld;
const lld S(1<<6);
lld n,m[S],count(0);
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
inline bool attack(lld num)
{
	for(register lld i=0;i<num;++i)
	{
		if(m[num]==m[i])return true;
		if(m[num]+num==m[i]+i)return true;
		if(m[num]-num==m[i]-i)return true;
	}
	return false;
}
inline void print()
{
	++count;
	for(register lld i(0);i<n;++i)
		printf("%5d",m[i]+1);
	putchar(10);
	return;
}
inline void dfs(lld nn)
{
	lld tot(n);
	for(m[nn]=0;m[nn]<tot;++m[nn])
	{
		if(attack(nn))continue;
		else if(nn!=n-1)dfs(nn+1);
		else print();
	}
	return;
}
int main()/*OpenG-qkmb*/
{
	n=getint();
	dfs(0);
	if(!count)puts("no solute!");
	return 0;
}