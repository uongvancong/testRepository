#include <iostream>
using namespace std;
struct Node{
	char c;
	Node *next;
};
struct Char{
	Node *node = NULL;
	int length = 0;
	void init(){
		node=NULL;
		length=0;
	}
	int size(){
		return length;
	}
	
	int isEmpty(){
		return node==NULL;
	}
	void insert(char c,int index){
		if(index<0 || index > length){
			cerr<<"Can't insert. Exception: out of size!"<<endl;
		}else{
			Node *temp,*start,*front;
			start=node;front=node;
			int i=0;
			temp=new Node;
			temp->c=c;
			temp->next=NULL;
			if(node==NULL){
				node=temp;
				length++;
				return;
			}
			while(i < index){
				front=node;
				node=node->next;
				i++;
			}
			if(index == 0){
				temp->next=start;
				node=temp;
			}else{
				if(index == length){
					front->next=temp;
					node=start;
				}else{
					front->next=temp;
					temp->next=node;
					node=start;
				}
			}
			length++;
		}
	}
	
	void add(char c){
		insert(c,length);
	}
	void remove(int index){
		if(index < 0 || index > length-1){
		
		 	cerr<<"Can't remove. Exception: out of size!"<<endl;
		}else{
			int i=0;
			Node *back, *front, *start;
			start=node;
			while(i< index){
				front=node;
				node=node->next;
				i++;
			}
			if( index == 0){
				node=node->next;
				delete start;
			}else{
				if( index == length-1){
					front->next=NULL;
					node=start;
				}else{
					front->next=node->next;
					delete node;
					node=start;
				}
			}
			length--;
		}
	}
	
	void update( Char c){
		node=c.node;
	}
	
	void readChar(){
		Node *temp=node;
		if(node==NULL){
			cout<<"NULL"<<endl;
			return;
		}
		while(!isEmpty()){
			cout<<node->c;
			node=node->next;
		}
		node=temp;
	}
	
	void readCharRev(){
		string p="";
		Node *temp=node;
		if(node==NULL){
			cout<<"NULL"<<endl;
			return;
		}
		while(!isEmpty()){
			p=node->c+p;
			node=node->next;
		}
		node=temp;
		cout<<p;
	}
};
main(){
	Char c;
	c.add('B');
	c.insert('U',1);
	c.insert('I',2);
	c.add('I');
	c.readChar();
	cout<<endl;
	c.remove(4);
	c.readChar();
	cout<<endl;
}
