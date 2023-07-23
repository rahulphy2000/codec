#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
int i,n;
ifstream input("datalog.txt");
float x[100],sumx,sumy,sumxx,sumxy,m,c,y[100];

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
sumx = sumx+(x[i]*x[i])/n;
sumxx = sumxx+(x[i]*x[i]*x[i]*x[i])/n;
sumy = sumy +y[i]/n;
sumxy = sumxy + (x[i]*x[i]*y[i])/n;
}

m=(sumxy-(sumx*sumy))/(sumxx*(sumx*sumx));
c=sumy-m*sumx;
cout<<"\nValue of constant a is "<<m;
cout<<"\nValue of constant b is "<<c;
return 0;
}
