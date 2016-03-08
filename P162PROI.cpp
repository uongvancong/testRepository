#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	if(s[0]!='-')
	{
		cout<<s;
		return 0;
	}
	if(s.size()==3&&s[2]=='0')
	{
		cout<<0;
		return 0;
	}
	long size = s.size();
	if(s[size-1] < s[size-2])
	{
		for(int i = 0 ; i < size -2;i++)
		{
			cout<<s[i];
		}
		cout<<s[size-1];
	}
	else
	{
		if(s[size-1]==s[size-2])
		{
			for(long i = 0 ; i < size-1 ; i ++)
			{
				cout<<s[i];
			}
			return 0;
		}
		for(int i = 0 ; i <= size -2;i++)
		{
			cout<<s[i];
		}
	}





	return 0;
}


