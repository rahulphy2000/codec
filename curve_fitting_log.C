#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main(void)
{
int i,n;
ifstream input("dataput.txt");
float x[100],y[100],sumx,sumxx,sumxy,sumy,c,m,a,b;
sumx=0;
sumy=0;
sumxx=0;
sumxy=0;

cout<<"Enter number of pairs: ";
cin>>n;
for(i=0;i<n;i=i+1)
{
input>>x[i];
input>>y[i];
}

for(i=0;i<n;i=i+1)
{
sumx=sumx+x[i]/n;
sumxx=sumxx+(x[i]*x[i])/n;
sumy=sumy+log(y[i])/n;
sumxy=sumxy+(x[i]*log(y[i]))/n;
}
m=(sumxy-(sumx*sumy))/(sumxx-(sumx*sumx));
c=sumy-m*sumx;
a=exp(c);
b=-m;
cout<<"\nValue of constant a is "<<a;
cout<<"\nValue of constant b is "<<b;
return 0;
}
