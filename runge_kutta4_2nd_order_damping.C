#include<iostream>
#include<fstream>
using namespace std;

float f(float x,float y,float z)
{
float p;
p=z;
return p;
}

float g(float x,float y,float z)
{
float p;
p=-0.2*z-y;
return p;
}

int main(void)
{
int i,n;
float x0,y0,z0,xn,yn,zn,k1,k2,k3,k4,m1,m2,m3,m4,h,m,k;

ofstream out1("rk3.txt");
ofstream out2("rk4.txt");

cout<<"Give initial values of x(0),y(0),y'(0) respectively:\n";
cin>>x0>>y0>>z0;
cout<<"Give value of xn: ";
cin>>xn;
cout<<"Give value of n: ";
cin>>n;

h=(xn-x0)/n;

for(i=0;i<n;i=i+1)
{
k1=h*f(x0,y0,z0);
m1=h*g(x0,y0,z0);
k2=h*f(x0+(h/2),y0+(k1/2),z0+(m1/2));
m2=h*g(x0+(h/2),y0+(k1/2),z0+(m1/2));
k3=h*f(x0+(h/2),y0+(k2/2),z0+(m2/2));
m3=h*g(x0+(h/2),y0+(k2/2),z0+(m2/2));
k4=h*f(x0+h,y0+k3,z0+m3);
m4=h*g(x0+h,y0+k3,z0+m3);
k=(1.0/6.0)*(k1+2*k2+2*k3+k4);
yn=y0+k;
y0=yn;
m=(1.0/6.0)*(m1+2*m2+2*m3+m4);
zn=z0+m;
z0=zn;
x0=x0+h;

out1<<x0<<"\t\t"<<y0<<endl;
out2<<x0<<"\t\t"<<z0<<endl;
}
return 0;
}
