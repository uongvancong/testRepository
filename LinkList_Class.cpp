#include<bits/stdc++.h>
using namespace std;
struct Node;
{
	char c;
	Node *next;
}

struct Char
{
	Node *node = NULL;
	int size = 0;
	void init()
	{
		node = NULL;
		length = 0;
	}
	int Size()
	{
		return length;
	}
	int isEmpty()
	{
	
		return node == NULL;
	}
	
	void insert(char c, int index)
	{
		if(index < 0 || index > length)
		{
			cerr << "Vi tri bi loi => khong chen duoc.";
		}
		else
		{
			Node *temp, *start
		}
	}
}

int main()
{
	





	return 0;
}


