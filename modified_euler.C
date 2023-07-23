#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

float f(float x,float y)
{
float z;
z=2*x*y;
return z;
}

int main(void)
{
int i,n;
float x0,y0,xn,yn,h,k1,k2;
 
cout<<"Give initial values of x0 and y0 respectively: \n";
cin>>x0>>y0;
cout<<"Give value of xn: ";
cin>>xn;
cout<<"Give value of n: ";
cin>>n;

ofstream out("data2.txt");

h=(xn-x0)/n;

for(i=1;i<n;i=i+1)
{
k1=h*f(x0,y0);
k2=h*f(x0+h,y0+k1);
yn=y0+(k1+k2)/2;
y0=yn;
x0=x0+h;

out<<x0<<"\t\t"<<y0<<endl;
}
return 0;
}
