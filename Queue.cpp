#include <iostream>
#include <queue>
using namespace std;
struct Node{
	int num;
	Node *next ;
};
struct Queue{
	Node *Front=NULL;
	Node *Back=NULL;
	void init(){
		Front=NULL;
		Back=NULL;
	}
	int isEmpty(){
		return Front==NULL;
	}
	//them phan tu vao queue
	void push(int x){
		Node *temp;
		temp=new Node;
		temp->num=x;
		temp->next=NULL;
		if(isEmpty()){
			Front=temp;
			Back=temp;
		}else{
			Back->next =temp;
			Back=temp;
		}
	}
	//lay phan tu dau
	int front(){
		return Front->num;
	}
	//loai bo phan tu dau cua queue
	int pop(){
		if(!isEmpty()){
			int front=Front->num;
			Front=Front->next;
			return front;
		}
	}
	void readQueue(){
		Node *temp=Front;
		while(!isEmpty()){
			cout<<pop()<<" ";
		}
		Front=temp;
	}
};
main(){
	Queue a;
	a.init();
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.readQueue();
}
