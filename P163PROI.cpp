#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long d1, d2, d3;
	cin>>d1>>d2>>d3;
	long long res = min(d1+d2+d3,d1*2+d2*2);
	res= min(res,d2*2+d3*2);
	res= min(d1*2+d3*2,res);
	cout<<res;





	return 0;
}


