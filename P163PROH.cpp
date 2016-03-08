#include<bits/stdc++.h>
using namespace std;
int check(int a[], int res)
{
	for(int i = 0 ; i < 22 ; i++)
	{
		if(res == a[i]) return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

int a[22] ={

60,
90,
108,
120,
135,
140,
144,
150,
156,
160,
162,
165,
168,
170,
171,
172,
174,
175,
176,
177,
178,
179

};
int t;
cin>>t;
int uvc;
while(t--)
{
	cin>>uvc;
	if(check(a,uvc)) cout<<"YES\n";
	else cout<<"NO\n";
}
	return 0;
}


