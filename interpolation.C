#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
int i,j,n;
float x[100],y[100][100],xx,h,s,sum,term;
ifstream in("dataint.txt");
cout<<"Give range: ";
cin>>n;
cout<<"Give year whose population will be calculated: ";
cin>>xx;
for(j=0;j<n;j=j+1)
{
 in>>x[j]>>y[0][j];
}
for(i=1;i<n;i=i+1)
{
for(j=0;j<(n-i);j=j+1)
{
y[i][j]=y[i-1][j+1]-y[i-1][j];
}
}
h=x[1]-x[0];
s=(xx-x[0])/h;
sum=y[0][0];
term=1;
for(i=1;i<n;i=i+1)
{
term=term*(s-i+1)/i;
sum=sum+term*y[i][0];
}
cout<<"The population of "<<xx<<" is "<<sum<<endl;
return 0;
}
