#include<iostream>
#include<fstream>
using namespace std;

float f(float x,float y)
{
float p;
p=-2*x*y;
return p;
}

int main(void)
{
int i,n;
float x0,y0,xn,yn,h,m;

ofstream out("da.txt");

cout<<"Give initial values of x(0) and y(0) respectively:\n";
cin>>x0>>y0;
cout<<"Give value of xn: ";
cin>>xn;
cout<<"Give value of n: ";
cin>>n;

h=(xn-x0)/n;

for(i=1;i<n;i=i+1)
{
m=h*f(x0,y0);
yn=y0+m;
x0=x0+h;
y0=yn;

out<<x0<<"\t\t"<<y0<<endl;
}
return 0;
}
