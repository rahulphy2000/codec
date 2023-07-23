#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
float f(float x,float y1,float y2)
{
float p;
p=((2*y1)+(3*y2));
return p;
}

float g(float x,float y1,float y2)
{
float q;
q=(y1-y2);
return q;
}

int main()
{
ofstream out("12.in");
float x,x0,y1,y10,y2,y20,xf,h,k1,k2,k3,k4,m1,m2,m3,m4;
cout<<"Provide the values of xf,h"<<endl;
cin>>xf>>h;
x0=0;
y10=1;
y20=1;
for(x=x0;x<xf;x=x+h)
{
k1=h*f(x,y10,y20);
m1=h*g(x,y10,y20);

k2=h*f(x+(h/2),y10+(k1/2),y20+(m1/2));
m2=h*g(x+(h/2),y10+(k1/2),y20+(m1/2));

k3=h*f(x+(h/2),y10+(k2/2),y20+(m2/2));
m3=h*g(x+(h/2),y10+(k2/2),y20+(m2/2));

k4=h*f(x+h,y10+k3,y20+m3);
m4=h*g(x+h,y10+k3,y20+m3);

y1=y10+((1.0/6.0)*(k1+(2*k2)+(2*k3)+k4));
y2=y20+((1.0/6.0)*(m1+(2*m2)+(2*m3)+m4));

y10=y1;
y20=y2;

out<<x+h<<"\t\t"<<y10<<"\t\t"<<y20<<"\t\t"<<endl;
}
return 0;
}
