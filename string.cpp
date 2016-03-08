#include<iostream>
#include <string>
using namespace std;
int check(char c, string s)
{
	for(int i = 0 ; i < s.size(); i++)
	{
		if(s[i] == c) return 1;
	}
	return 0;
}
void solve(string s1, string s2)
{
	for(int i = 0 ; i < s1.size() ; i++)
	{
		if(check(s1[i], s2)) cout<< s1[i]<<endl;
	}
}
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	
	solve(s1, s2);





	return 0;
}


