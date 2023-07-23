#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
float f(float t,float y,float z)
{
float q;
q=z;
return q;
}

float g(float t,float y,float z)
{
float r;
r=cos(t)-y;
return r;
}

int main()
{
ofstream out("10.in");
float t,t0,y,y0,z,z0,tf,h,k1,k2,k3,k4,m1,m2,m3,m4;
cout<<"provide the values of tf and h respectively"<<endl;
cin>>tf>>h;
t0=0;
y0=1;
z0=1;
for(t=t0;t<tf;t=t+h)
{
k1=h*f(t,y0,z0);
m1=h*g(t,y0,z0);

k2=h*f(t+(h/2),y0+(k1/2),z0+(m1/2));
m2=h*g(t+(h/2),y0+(k1/2),z0+(m1/2));

k3=h*f(t+(h/2),y0+(k2/2),z0+(m2/2));
m3=h*g(t+(h/2),y0+(k2/2),z0+(m2/2));

k4=h*f(t+h,y0+k3,z0+m3);
m4=h*f(t+h,y0+k3,z0+m3);

y=y0+(1.0/6.0)*(k1+(2*k2)+(2*k3)+k4);
z=z0+(1.0/6.0)*(m1+(2*m2)+(2*m3)+m4);

y0=y;
z0=z;
out<<t+h<<"\t\t"<<y0<<"\t\t"<<z0<<endl;
}
return 0;
}
