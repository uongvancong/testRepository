#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long n;
	cin>>n;
	long res = 0;
	while(n)
	{
		res++;
		long temp = 1;
		while(temp*2 <= n )
		{
			temp*=2;
		}
		n-=temp;
//		cout<<temp<<" "<<n<<endl;
	}
	cout<<res;




	return 0;
}


