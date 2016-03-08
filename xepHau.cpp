#include <iostream>
using namespace std;
int banCo[101][101]={0,0},n,cheo1[201]={0},cheo2[201]={0}, cot[101]={0},count=0;
void result(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<banCo[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void xepHau(int i){
	for(int j=1;j<=n;j++){
		if(!cot[j] && !cheo1[i+j] && !cheo2[n+i-j]){
			cot[j]=1; cheo1[i+j]=1; cheo2[n+i-j]=1; banCo[i][j]=1;
			if(i==n){
				result();
				count++;
			}else{
				xepHau(i+1);
			}
			cot[j]=0; cheo1[i+j]=0; cheo2[n+i-j]=0; banCo[i][j]=0;
		}
	}
}
main(){
	cin>>n;
	xepHau(1);
	cout<<count;
}
