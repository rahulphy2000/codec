#include<iostream>
#include<cmath>
using namespace std;

float u(float x,float y)
{
return (x*x-y*y+1);
}

float v(float x,float y)
{
return (2*x*y);
}

float ux(float x,float y)
{
return (2*x);
}

float vx(float x,float y)
{
return (2*y);
}

float uy(float x,float y)
{
return (-2*y);
}

float vy(float x,float y)
{
return (2*x);
}

int main(void)
{
float d,x0,y0,x,y,err,s;

cout<<"Give guess values of x0 and y0:\n";
cin>>x0>>y0;

err=0.0001;
s=200;

while(abs(s)>err)
{
d=ux(x0,y0)*vy(x0,y0)-uy(x0,y0)*vx(x0,y0);
x=x0-(1.0/d)*((vy(x0,y0)*u(x0,y0))-(uy(x0,y0)*v(x0,y0)));
x0=x;
y=y0-(1.0/d)*((-vx(x0,y0)*u(x0,y0))+(ux(x0,y0)*v(x0,y0)));
y0=y;
s=u(x0,y0)*u(x0,y0)+v(x0,y0)*v(x0,y0);
}
cout<<"The real root is: "<<x0<<endl;
cout<<"The imaginary root is: "<<y0<<endl;
return 0;
}
