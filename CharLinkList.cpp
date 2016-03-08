/*
 * C++ Program to Implement Singly Linked List
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node 
{ //Bieu dien Node
    char info;
    struct node *next;
}*start;
class single_llist { //Bieu dien lop
    public:
        node* create_node(char);//Tao mot node
        void insert_begin(); //Them node vao dau
        void insert_pos(); //Them node vao vi tri cho truoc
        void insert_last(); //Them node vao cuoi
        void delete_pos(); //Loai node tai vi tri cho truoc
        void update(); //Cap nhat thong tin node
        void reverse(); //Dao nguoc danh sach
        void display(); //Hien thi danh sach
        single_llist(){//Constructor
            start = NULL;
        }
};
node *single_llist::create_node(char value)
{
    struct node *temp, *s; //Khai bao hai con tro Node *temp, *s
    temp = new(struct node); //Cap phat bo nho cho temp
    if (temp == NULL)
	{ //Neu khong gian nho day
        cout<<"Khong du bo nho de cao phat"<<endl;
        return 0;
    }
    else 
	{
        temp->info = value;//Thiet lap thanh phan thong tin
        temp->next = NULL; //Thiet lap thanh phan lien ket    
        return temp;//Tra lai ket qua
    }
}
void single_llist::insert_begin(){ //Chen node vao dau
    char value;
    cout<<"Nhap gia tri node:"; cin>>value;
    struct node *temp, *p;
    temp = create_node(value);//Tao node can them
    if (start == NULL){//Neu danh sach rong
        start = temp;
        start->next = NULL;          
    } 
    else {
        p = start;
        start = temp;
        start->next = p;
    }
    cout<<"Hoan thanh them node vao dau"<<endl;
}
 

void single_llist::insert_last(){//Them node vao cuoi
    char value;
    cout<<"Nhap gia tri cho node: ";cin>>value;
    struct node *temp, *s;
    temp = create_node(value);//Tao node moi
    s = start;
    while (s->next != NULL){ //Di chuyen den node cuoi cung         
        s = s->next;        
    }
    temp->next = NULL;
    s->next = temp; //Thiet lap lien ket cho node
    cout<<"Hoan thanh them node vao cuoi"<<endl;  
}
void single_llist::insert_pos(){//Them node vao vi tri cho truoc
    char value;
	int pos, counter = 0; 
    cout<<"Nhap gia tri node:";cin>>value;
    struct node *temp, *s, *ptr;
    temp = create_node(value);//Tao node
    cout<<"Vi tri node can them: ";cin>>pos;
    int i; s = start; 
    while (s != NULL){
        s = s->next; counter++;
    }
    if (pos == 1){ //Neu vi tri dau tien
        if (start == NULL){//Neu danh sach rong
            start = temp;
            start->next = NULL;
        }
        else {
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }
    else if (pos > 1  && pos <= counter){
        s = start;
        for (i = 1; i < pos; i++){//Di chuyen den vi tri pos
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;//Thiet lap lien ket cho node
        temp->next = s;
    }
    else {
        cout<<"Vuot qua gioi han danh sach"<<endl;
    }
}

void single_llist::delete_pos(){//Loai phan tu o vi tri cho truoc
    int pos, i, counter = 0;
    if (start == NULL){ //Neu danh sach rong
        cout<<"Khong the thuc hien"<<endl;
        return;
    }
    cout<<"Vi tri can loai bo:";cin>>pos;
    struct node *s, *ptr;
    s = start; //s tro den dau danh sach
    if (pos == 1){ //Neu la node dau tien
        start = s->next;
        s->next = NULL;
    }
    else {
        while (s != NULL) {//Dem so  node cua danh sach
            s = s->next;
            counter++;  
        }
        if (pos > 0 && pos <= counter){ //Neu vi tri trong danh sach
            s = start;
            for (i = 1;i < pos;i++){ //Chuyen den Pos
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next; //Thiet lap lien ket cho node
        }
        else {
            cout<<"Vi tri ngoai danh sach"<<endl;
        }
        free(s);
        cout<<"Node da bi loai bo"<<endl;
    }
}
void single_llist::update(){//Sua doi thong tin node
    char value;
	int pos, i;
    if (start == NULL){
        cout<<"Danh sach rong"<<endl;
        return;
    }
    cout<<"Vi tri node can sua doi:";cin>>pos;
    cout<<"Gia tri moi cua node:";cin>>value;
    struct node *s, *ptr;
    s = start; //s tro den node dau tien
    if (pos == 1){//Neu la node dau tien
        start->info = value; //Cap nhat node
    }
    else {
        for (i = 0;i < pos - 1;i++){//Chyen den node pos
            if (s == NULL){//Neu node rong
                cout<<"Vi tri "<<pos<<" khong hop le";
                return;
            }
            s = s->next;
        }
        s->info = value;  //Cap nhat thong tin node
    }
    cout<<"Sua doi thanh cong"<<endl;
} 

void single_llist::reverse(){//Dao nguoc danh sach
    struct node *ptr1, *ptr2, *ptr3;
    if (start == NULL) {//Neu danh sach rong
        cout<<"Danh sach rong"<<endl;
        return;
    }
    if (start->next == NULL){//Neu chi co mot node
        return;
    }  
    ptr1 = start; //ptr1 tro den node dau tien
    ptr2 = ptr1->next;//ptr2 tro den node ke tiep
    ptr3 = ptr2->next;//ptr3 tro den node ke tiep ptr2
    ptr1->next = NULL;//Ngat lien ket ptr1
    ptr2->next = ptr1;//Thiet lap lien ket cho ptr2
    while (ptr3 != NULL){//Lap neu ptr3 khong rong
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;         
    }
    start = ptr2;
}
void single_llist::display(){//Hien thi danh sach
    struct node *temp;
    if (start == NULL){
        cout<<"Danh sach rong"<<endl;
        return;
    }
    temp = start;
    cout<<"Noi dung danh sach: "<<endl;
    while (temp != NULL) {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
main(){//Chuon trinh chinh
    int choice, nodes, element, position, i;
    single_llist sl; start = NULL;
    while (1){
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Thao tac tren danh sach lien ket don"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Them node vao dau danh sach"<<endl;
        cout<<"2.Them node vao cuoi danh sach"<<endl;
        cout<<"3.Them node vao node hien tai"<<endl;
        cout<<"5.Loai node o vi tri xac dinh"<<endl;
        cout<<"6.Sua doi noi dung node"<<endl;
        cout<<"8.Hien thi no dung danh sach"<<endl;
        cout<<"9.Dao nguoc danh sach "<<endl;
        cout<<"10.Thoat "<<endl;
        cout<<"Lua cho chuc nang: "; cin>>choice;
        switch(choice){
            case 1:
                 cout<<"Chen node vao dau: "<<endl;
                 sl.insert_begin();cout<<endl;
                 break;
            case 2:
                 cout<<"Chen node vao cuoi: "<<endl;
                 sl.insert_last();cout<<endl;
                 break;
            case 3:
                 cout<<"Chen node tai vi tri xac dinh:"<<endl;
                 sl.insert_pos();cout<<endl;
                 break;
            
            case 5:
                 cout<<"Loai bo node tai vi tri: "<<endl;
                 sl.delete_pos();
                 break;
            case 6:
                 cout<<"Sua doi gia tri node:"<<endl;  
                 sl.update();cout<<endl;
                 break;
            
            case 8:
                 cout<<"Danh sach duoc hien thi:"<<endl;
                 sl.display();cout<<endl;
                 break;
            case 9:
                 cout<<"Dao nguoc danh sach"<<endl;
                 sl.reverse();cout<<endl;
                 break;
            case 10:
                 cout<<"Thoat..."<<endl;
                 exit(1);
                 break;  
            default:
                    cout<<"Lua chon sai"<<endl;
        }
    }
}
