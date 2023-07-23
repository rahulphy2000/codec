#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
int i,n;
ifstream input("datacurve.txt");
float sumx,sumxx,sumxy,sumy,x[100],y[100],m,c;
sumx=0;
sumxx=0;
sumxy=0;
sumy=0;

cout<<"Enter the number of pairs: ";
cin>>n;

for(i=0;i<n;i=i+1)
{
input>>x[i];
input>>y[i];
}
for(i=0;i<n;i=i+1)
{
sumx = sumx+x[i]/n;
sumy = sumy+y[i]/n;
sumxx = sumxx+(x[i]*x[i])/n;
sumxy = sumxy+(x[i]*y[i])/n;
}
m=(sumxy-(sumx*sumy))/(sumxx-(sumx*sumx));
c=sumy-(m*sumx);
cout<<"\nValues of constant a is "<<m;
cout<<"\nValues of constant b is "<<c;
return 0;
}

