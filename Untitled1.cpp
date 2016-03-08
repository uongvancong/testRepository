#include<bits/stdc++.h>
using namespace std;
int check(string s)
{
	int sum1 = 0;
	int sum2 = 0;
	for(int i = 0 ; i < s.size()/2 ; i++)
	{
		sum1 += (s[i]-'0');
	}
	for(int i = s.size()/2 ; i < s.size() ; i++)
	{
		sum2 += (s[i]-'0');
	}
	if(sum1 == sum2) return 1;
	return 0;
	
}
int solve(string s)
{
	
	int mx = s.size() - s.size()%2;
	for(int i = mx ; i > 0 ; i-=2)
	{
		for(int k = 0 ; k < (s.size() - mx);k++)
		{
			string temp = "";
			for(int j = i ; j < mx+i ; j++)
			{
				temp += s[j];
			}
			if(check(temp))
			{
				return mx;
			}
			
		}
	}
	return 0;
}

int main()
{
	string s;
	cin>>s;
	if(!solve(s))
	{
		cout<<"Khong thoa man";
	}
	else
	{
		cout<<solve(s);
	}



	return 0;
}


