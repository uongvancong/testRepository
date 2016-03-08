#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int GiaTri;
	struct node *ConTro;
} * BatDau;
class DSLK
{
	public:
		Node *TaoNode(int x)
		{
			cout<<"Nhap gia tri node";cin>>x;
			Node *temp;	
			temp = new (struct node);
			if(temp == NULL)
			{
				cout<<"Khong du bo nho de cap phapt";
				return 0;
			}
			else
			{
				temp->GiaTri = x;
				temp->ConTro = NULL;
				return temp;
			}
		}
		void ThemDau()
		{
			int x;
			cout<<"Nhap gia tri cho node : ";cin>>x;
			Node *temp, *p;
			temp = TaoNode(x);
			if(BatDau == NULL)
			{
				BatDau = temp;
				BatDau->ConTro = NULL;	
			}	
			else 
			{
				
			}
		}	
}
int main()
{






	return 0;
}


