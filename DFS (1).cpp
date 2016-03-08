#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int arr[101][101],n,check[101]={0};
vector<int>point;

vector<int> danhSachDinh(int arr[][101],int n){
	vector<int>p;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(arr[i][j]==1){
				p.push_back(i);
				break;
			}
		}
	}
	return p;
}
void input(){
	freopen("DFS.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		}
	}
	point=danhSachDinh(arr,n);
}

void init(){
	for(int i=0;i<=n;i++) check[i]=0;
}
void DFS(int a[][101],int i){
	check[i]=1;
	for(int j=1;j<=n;j++){
		if(!check[j]&& a[i][j]){
			DFS(a,j);
		}
	}
}
//xoa mot dinh ke
void xoaMotDinh(int arr[][101],int n,int arrCopy[][101],int dinh,int dinhKe){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arrCopy[i][j]=arr[i][j];
		}
	}
	arrCopy[dinh][dinhKe]=0;
}
//xoa mot canh
void xoaMotCanh(int arr[][101],int n,int arrCopy[][101],int dinh1,int dinh2){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arrCopy[i][j]=arr[i][j];
		}
	}
	arrCopy[dinh1][dinh2]=0;
	arrCopy[dinh2][dinh1]=0;
}
int soThanhPhanLienThong(int a[101][101],int n,vector<int>point){
	int count=0,ok=1,k;
	init();
	while(ok){
		ok=0;
		for(int i=0;i<point.size();i++){
			if(check[point[i]]==0){
				ok=1;
				k=point[i]; 
				break;
			}
		}
		if(ok){
			DFS(a,k);
			count++;
		}
	}
	return count;
}
//kt 1 dinh co la tru hay khong
int ktDinhTru(int dinh, int stplt){
	int arrKT[101][101],thanhPhanLienThong;
	vector<int>dinhke;
	for(int i=1;i<=n;i++){
		if(arr[dinh][i]) dinhke.push_back(i);
	}
	for(int v=0;v<dinhke.size();v++){
		xoaMotDinh(arr,n,arrKT,dinh,dinhke[v]);
		thanhPhanLienThong=soThanhPhanLienThong(arrKT,n,point);
		if(thanhPhanLienThong>stplt) return 1;
	}
	return 0;
}
//liet ke cac dinh tru
void dinhTru(int arr[101][101],int n){
	int stplt=soThanhPhanLienThong(arr,n,point),ok=1;
	for(int i=1;i<=n;i++){
		if(ktDinhTru(i,stplt)){
			cout<<i<<" ";
			ok=0;
		}
	}
	if(ok) cout<<"Do thi khong co dinh tru";
}
//kiem tra 1 canh co phai canh cau hay khong
int ktCanhCau(int dinh1,int dinh2,int stplt){ 
	 int arrCopy[101][101],thanhPhanLienThong=0;
	 vector<int>p;
	 xoaMotCanh(arr,n,arrCopy,dinh1,dinh2);
	 p=danhSachDinh(arrCopy,n);
	 thanhPhanLienThong=soThanhPhanLienThong(arrCopy,n,p);
	 if(thanhPhanLienThong>stplt) return 1;
	 return 0;
}
//liet ke cac canh cau
void canhCau(int arr[][101],int n){
	int ok=1,stplt=soThanhPhanLienThong(arr,n,point);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(arr[i][j]){
				if(ktCanhCau(i,j,stplt)){
					cout<<i<<" "<<j<<endl;
					ok=0;
				}
			}
		}
	}
	if(ok) cout<<"Do thi vo huong khong co canh cau";
}
main(){
	input();
	cout<<"So thanh phan lien thong: ";
	cout<<soThanhPhanLienThong(arr,n,point)<<endl;
	cout<<"Cac dinh tru: ";
	dinhTru(arr,n);
	cout<<endl<<"Cac canh cau: "<<endl;
	canhCau(arr,n);
}
