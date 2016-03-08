#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long n, x;
	cin>>n>>x;
	long res = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		long temp = x;
		if(temp%i==0)
		{
			temp/=i;
			if(temp<=n) res++;
		}
	}
	cout<<res;





	return 0;
}


