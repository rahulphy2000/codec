#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

float f(float x,float y)
{
float z;
z=-2*x*y;
return (z);
}

int main(void)
{
int i,n;
float k1,k2,x0,y0,yn,h,xn;

ofstream out("data.txt");

cout<<"Give initial values of x0 and y0 respectively:\n";
cin>>x0>>y0;
cout<<"Give value of xn: ";
cin>>xn;
cout<<"Give value of n: ";
cin>>n;

h=(xn-x0)/n;

for(i=1;i<n;i=i+1)
{
k1=h*f(x0,y0);
k2=h*f(x0+h,y0+k1);
yn=y0+(k1+k2)/2;
x0=x0+h;
y0=yn;

out<<x0<<"\t\t"<<y0<<endl;
}
return 0;
}

