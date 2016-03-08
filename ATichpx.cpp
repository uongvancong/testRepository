//#include<conio.h>
#include<stdio.h>
#include<math.h>

#define ll long long
int ktnt(ll n)
{
if(n<2) return 0;
if(n==2) return 1;
if(n%2==0) return 0;
for(ll k=3; k*k<=n;k+=2)
if(n%k==0) return 0;
return 1;
}
int gan(ll n)
{
if(n<4) return 0;
if(n==4) return 1;
if(n%4!=1) return 0;
ll k=sqrt(n);
if(k*k!=n) return 0;
return ktnt(k);
}

int main()
{
int K[100005];
long n;
long long x;
scanf("%ld",&n);
for(int i=1;i<=n;i++)
{
scanf("%lld",&x);
K[i]=gan(x);
}
for(int i=1;i<=n;i++)
if(K[i]) printf("YES\n"); else printf("NO\n");
// getch();
}
