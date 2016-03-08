#include<bits/stdc++.h>
using namespace std;
long kq(string s)
{
	long res = 0;
	for(int i = 0 ; i < s.size() ; i ++)
	{
		if(s[i] != '0')
		{
			res = res *10 + (s[i] -'0');
		}
	}
	return res;
}
long uvc(string s)
{
	long res = 0;
	for(int i = 0 ; i < s.size() ; i ++)
	{
			res = res *10 + (s[i] -'0');
	}
	return res;
}
string ahihi(long n)
{
	string s = "";
	while(n!=0)
	{
		char temp = '0' + n%10;
		s = temp +s;
		n/=10;
	}
	return s;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b;
	cin>>a>>b;
	long uvca = kq(a), uvcb = kq(b);
	long ra = uvc(a) + uvc(b);
	long uvcc = kq(ahihi(ra));
	if(uvca + uvcb == uvcc) cout<<"YES";
	else
	cout<<"NO";
	
	return 0;
}


