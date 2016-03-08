#include <iostream>
using namespace std;

struct Node{
	int num;
	Node *next;
};
struct Stack{
	Node *top;
};
void init(Stack &s){
	s.top=NULL;
}
int isEmpty(Stack s){
	return s.top==NULL;
}
void push(Stack &s,int x){
	Node *temp;
	temp=new Node;
	temp->num=x;
	temp->next=s.top;
	s.top=temp;
}
int top(Stack s){
	return s.top->num;
}
int pop(Stack &s){
	if(!isEmpty(s)){		
		int num=s.top->num;
		s.top=s.top->next;
		return num;
	}
}
int len(Stack s){
	int length=0;
	while(!isEmpty(s)){
		length++;
		s.top=s.top->next;
	}
	return length;
}
void DFS(int arr[],int n){
	Stack s;
	
}
main(){
	int arr[100][100],n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	
}
