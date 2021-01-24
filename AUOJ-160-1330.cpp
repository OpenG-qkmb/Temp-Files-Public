#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long lld;
const lld S(1<<19);
int n,cnt(1),a[S],b[S],l(1),r(1),ans(-1),mid;
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
int main()/*OpenG-qkmb*/
{
	b[cnt]=1,n=getint();
	for(register lld i(1);i<=n;++i)
	{
		a[i]=getint();
	}
	sort(a+1,a+n+1);
	for(register lld i(2);i<=n;++i)
	{
		l=1,r=cnt,ans=-1;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(a[i]>=b[mid])ans=mid,r=mid-1;
			else l=mid+1;
		}
		if(ans==-1)b[++cnt]=1;
		else ++b[ans];
	}	
	return putint(cnt),putchar(10),0;
}