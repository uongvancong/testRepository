#include <iostream>
#include <fstream>
using namespace std;

struct Node{
	int num;
	Node *next;
};
struct Stack{
	int len=0;
	Node *Top=NULL;
	//khoi tao, tao moi stack
	void init(){
		Top=NULL;
		len=0;
	}
	//kiem tra stack rong hay khong. rong tra ve 1.
	int isEmpty(){
		return Top==NULL;
	}
	//them phan tu vao stack
	void push(int x){
		Node *temp;
		temp=new Node;
		temp->num=x;
		temp->next=Top;
		Top=temp;
		len++;
	}
	//lay ra phan tu o top
	int top(){
		return Top->num;
	}
	//loai bo phan tu o top va tra ve gia tri top
	int pop(){
		if(!isEmpty()){
			int top=Top->num;
			Top=Top->next;
			len--;
			return top;
		}
	}
	int length(){
		return len;
	}
	//doc cac phan tu cua stack
	void readStack(){
		Node *temp=Top;
		int l=len;
		while(!isEmpty()){
			cout<<pop()<<" ";
		}
		Top=temp;
		len=l;
	}
};

int check[101]={0};
int arr[101][101],n;
void DfsStack(int k){
	Stack s;
	int temp;
	s.push(k);
	check[k]=1;
	cout<<k<<" ";
	while(!s.isEmpty()){
		temp=s.pop();
		for(int i=1;i<=n;i++){
			if(arr[temp][i]&& !check[i]){
				s.push(temp);
				s.push(i);
				cout<<i<<" ";
				check[i]=1;
				break;
			}
		}	
	}
}
main(){
	freopen("DFS.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		}
	}
	DfsStack(1);
}
