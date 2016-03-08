#include<bits/stdc++.h>
using namespace std;
string multiply(string s1, int n)
{
	if(n == 10 ) 
	{
		return (s1 + '0');
		
	}
	string s = "";
	int nho = 0;
	for(int i = s1.size()-1; i >=0 ; i--)
	{
		int temp = (s1[i] - '0') * n + nho;
		if(temp > 9)
		{
			char f = ( temp - temp/10*10 ) + '0';
			s = f + s;
			nho = temp / 10; 
		}
		else
		{
			char f =  temp  + '0';
			s = f + s;
			nho = 0;
		}
	}
	if(nho!=0) 
	{
		char f = nho + '0';
		s = f + s;
	}
	return s;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	int check = 0;
	string res = "";
	if(s[0] == '?')
	{
		res = "9";
	}
	if(s[0] <= 'J' && s[0] >= 'A')
	{
		res = '9';
		int check = 1;
	}
	int a[10];
	for(int i = 0 ; i < 10 ; i ++ ) a[i] = 0;
	for(int i = 1 ; i < s.size() ; i ++)
	{
		if(s[i] <= 'J' && s[i] >= 'A') 
		{
			a[(((int)s[i]) - 65)]++;
			
		}
	}
	int count  = 0;
	for(int i = 0 ; i < 10 ; i ++)
	{
		if(a[i]!=0) count++;
	}
	sort(a,a+10);
	if(check==1 && ((count == 10) || ((count == 9) && a[(((int)s[0]) - 65)] == 0)) )
	




	return 0;
}


