#include<iostream>
#include<cmath>
using namespace std;

float f(float x)
{
return (x*x-5*x+6);
}
float g(float x)
{
return (2*-5);
}

int main(void)
{
float x0,x,h,err;

cout<<"Give guess value x0: ";
cin>>x0;

h=f(x0)/g(x0);
err=0.0001;

while(abs(h)>err)
{
h=f(x0)/g(x0);
x=x0-h;
x0=x;
}
cout<<"The root of the equation is "<<x0<<endl;
return 0;
}
